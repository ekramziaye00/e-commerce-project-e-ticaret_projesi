#include "../../include/services/ETicaretServisi.hpp"
#include "../utils/TarihUtils.h"
#include <stdexcept>
#include <map>

ETicaretServisi::ETicaretServisi(
    Depo<Musteri>& musteriDepo, Depo<Adres>& adresDepo,
    Depo<Kategori>& kategoriDepo, Depo<Urun>& urunDepo,
    Depo<Siparis>& siparisDepo, Depo<SiparisKalemi>& siparisKalemiDepo,
    Depo<Odeme>& odemeDepo
) : _musteriDepo(musteriDepo), _adresDepo(adresDepo),
    _kategoriDepo(kategoriDepo), _urunDepo(urunDepo),
    _siparisDepo(siparisDepo), _siparisKalemiDepo(siparisKalemiDepo),
    _odemeDepo(odemeDepo)
{
}

void ETicaretServisi::musteriKaydet(const std::string& email, const std::string& ad_soyad, const std::string& telefon) {
    std::string kayit_tarihi = TarihUtils::bugunTarihi();
    int yeni_id = _musteriDepo.boyut() + 1;
    auto musteri = std::make_shared<Musteri>(yeni_id, email, ad_soyad, telefon, kayit_tarihi);
    _musteriDepo.ekle(musteri);
}

void ETicaretServisi::urunEkle(const std::string& ad, const std::string& aciklama, double fiyat, int stok, int kategori_id) {
    int yeni_id = _urunDepo.boyut() + 1;
    auto urun = std::make_shared<Urun>(yeni_id, ad, aciklama, fiyat, stok, kategori_id);
    _urunDepo.ekle(urun);
}

int ETicaretServisi::siparisOlustur(int musteri_id, int adres_id) {
    auto musteri = _musteriDepo.getir(musteri_id);
    auto adres = _adresDepo.getir(adres_id);
    
    std::string tarih = TarihUtils::bugunTarihi();
    int yeni_id = _siparisDepo.boyut() + 1;
    auto siparis = std::make_shared<Siparis>(yeni_id, musteri_id, adres_id, tarih, "Bekliyor", 0.0);
    _siparisDepo.ekle(siparis);
    
    return yeni_id;
}

void ETicaretServisi::sipariseUrunEkle(int siparis_id, int urun_id, int miktar) {
    auto siparis = _siparisDepo.getir(siparis_id);
    auto urun = _urunDepo.getir(urun_id);
    
    int yeni_id = _siparisKalemiDepo.boyut() + 1;
    auto kalem = std::make_shared<SiparisKalemi>(yeni_id, siparis_id, urun_id, miktar, urun->get_fiyat());
    _siparisKalemiDepo.ekle(kalem);
    
    double yeni_tutar = siparis->get_toplam_tutar() + (urun->get_fiyat() * miktar);
    siparis->set_toplam_tutar(yeni_tutar);
    _siparisDepo.guncelle(siparis);
}

void ETicaretServisi::siparisOnayla(int siparis_id) {
    auto siparis = _siparisDepo.getir(siparis_id);
    siparis->set_durum("Onaylandi");
    _siparisDepo.guncelle(siparis);
    
    auto kalemler = _siparisKalemiDepo.ara([siparis_id](const std::shared_ptr<SiparisKalemi>& k) {
        return k->get_siparis_id() == siparis_id;
    });
    
    for (const auto& kalem : kalemler) {
        auto urun = _urunDepo.getir(kalem->get_urun_id());
        int yeni_stok = urun->get_stok() - kalem->get_miktar();
        urun->set_stok(yeni_stok);
        _urunDepo.guncelle(urun);
    }
}

void ETicaretServisi::siparisIptalEt(int siparis_id) {
    auto siparis = _siparisDepo.getir(siparis_id);
    siparis->set_durum("Iptal");
    _siparisDepo.guncelle(siparis);
}

void ETicaretServisi::odemeAl(int siparis_id, const std::string& yontem, double tutar) {
    auto siparis = _siparisDepo.getir(siparis_id);
    
    std::string tarih = TarihUtils::bugunTarihi();
    int yeni_id = _odemeDepo.boyut() + 1;
    auto odeme = std::make_shared<Odeme>(yeni_id, siparis_id, yontem, tutar, tarih, "Onaylandi");
    _odemeDepo.ekle(odeme);
}

void ETicaretServisi::stokGuncelle(int urun_id, int yeni_stok) {
    auto urun = _urunDepo.getir(urun_id);
    urun->set_stok(yeni_stok);
    _urunDepo.guncelle(urun);
}

std::vector<std::shared_ptr<Siparis>> ETicaretServisi::musteriSiparisGecmisi(int musteri_id) {
    return _siparisDepo.ara([musteri_id](const std::shared_ptr<Siparis>& s) {
        return s->get_musteri_id() == musteri_id;
    });
}

std::vector<std::shared_ptr<Urun>> ETicaretServisi::kategoriUrunleri(int kategori_id) {
    return _urunDepo.ara([kategori_id](const std::shared_ptr<Urun>& u) {
        return u->get_kategori_id() == kategori_id;
    });
}

std::vector<std::shared_ptr<Urun>> ETicaretServisi::enCokSatanUrunler(int limit) {
    std::map<int, int> urun_satis_sayisi;
    
    auto tum_kalemler = _siparisKalemiDepo.tumunu();
    for (const auto& kalem : tum_kalemler) {
        urun_satis_sayisi[kalem->get_urun_id()] += kalem->get_miktar();
    }
    
    std::vector<std::pair<int, int>> satis_listesi;
    for (const auto& pair : urun_satis_sayisi) {
        satis_listesi.push_back(pair);
    }
    
    std::sort(satis_listesi.begin(), satis_listesi.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        });
    
    std::vector<std::shared_ptr<Urun>> sonuc;
    int sayac = 0;
    for (const auto& pair : satis_listesi) {
        if (sayac >= limit) break;
        auto urun = _urunDepo.getir(pair.first);
        sonuc.push_back(urun);
        sayac++;
    }
    
    return sonuc;
}
