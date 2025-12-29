#ifndef ETICARET_SERVISI_HPP
#define ETICARET_SERVISI_HPP

#include <memory>
#include <vector>
#include <string>
#include "../repositories/Depo.hpp"
#include "../entities/Musteri.hpp"
#include "../entities/Adres.hpp"
#include "../entities/Kategori.hpp"
#include "../entities/Urun.hpp"
#include "../entities/Siparis.hpp"
#include "../entities/SiparisKalemi.hpp"
#include "../entities/Odeme.hpp"

class ETicaretServisi {
private:
    Depo<Musteri>& _musteriDepo;
    Depo<Adres>& _adresDepo;
    Depo<Kategori>& _kategoriDepo;
    Depo<Urun>& _urunDepo;
    Depo<Siparis>& _siparisDepo;
    Depo<SiparisKalemi>& _siparisKalemiDepo;
    Depo<Odeme>& _odemeDepo;

public:
    ETicaretServisi(
        Depo<Musteri>& musteriDepo, Depo<Adres>& adresDepo,
        Depo<Kategori>& kategoriDepo, Depo<Urun>& urunDepo,
        Depo<Siparis>& siparisDepo, Depo<SiparisKalemi>& siparisKalemiDepo,
        Depo<Odeme>& odemeDepo
    );

    ~ETicaretServisi() = default;

    void musteriKaydet(const std::string& email, const std::string& ad_soyad, const std::string& telefon);
    void urunEkle(const std::string& ad, const std::string& aciklama, double fiyat, int stok, int kategori_id);
    int siparisOlustur(int musteri_id, int adres_id);
    void sipariseUrunEkle(int siparis_id, int urun_id, int miktar);
    void siparisOnayla(int siparis_id);
    void siparisIptalEt(int siparis_id);
    void odemeAl(int siparis_id, const std::string& yontem, double tutar);
    void stokGuncelle(int urun_id, int yeni_stok);
    std::vector<std::shared_ptr<Siparis>> musteriSiparisGecmisi(int musteri_id);
    std::vector<std::shared_ptr<Urun>> kategoriUrunleri(int kategori_id);
    std::vector<std::shared_ptr<Urun>> enCokSatanUrunler(int limit);
};

#endif
