#include <iostream>
#include <memory>
#include "../include/repositories/Depo.hpp"
#include "../include/entities/Musteri.hpp"
#include "../include/entities/Adres.hpp"
#include "../include/entities/Kategori.hpp"
#include "../include/entities/Urun.hpp"
#include "../include/entities/Siparis.hpp"
#include "../include/entities/SiparisKalemi.hpp"
#include "../include/entities/Odeme.hpp"
#include "../include/services/ETicaretServisi.hpp"

using namespace std;

int main() {
    cout << "=== E-TİCARET SİPARİŞ SİSTEMİ ===" << endl;
    cout << "Çok Katmanlı Mimari Projesi" << endl;
    cout << "=================================" << endl << endl;

    // 1. Depoları oluştur
    cout << "[1] Depolar oluşturuluyor..." << endl;
    Depo<Musteri> musteriDepo;
    Depo<Adres> adresDepo;
    Depo<Kategori> kategoriDepo;
    Depo<Urun> urunDepo;
    Depo<Siparis> siparisDepo;
    Depo<SiparisKalemi> siparisKalemiDepo;
    Depo<Odeme> odemeDepo;

    // 2. Servisi oluştur
    cout << "[2] Servis oluşturuluyor..." << endl;
    ETicaretServisi eticaret(
        musteriDepo, adresDepo, kategoriDepo, urunDepo,
        siparisDepo, siparisKalemiDepo, odemeDepo
    );

    // 3. Örnek veri yükle
    cout << "[3] Örnek veriler yükleniyor..." << endl << endl;

    // Kategoriler
    auto kat1 = make_shared<Kategori>(1, "Elektronik", 0);
    auto kat2 = make_shared<Kategori>(2, "Telefon", 1);
    auto kat3 = make_shared<Kategori>(3, "Bilgisayar", 1);
    kategoriDepo.ekle(kat1);
    kategoriDepo.ekle(kat2);
    kategoriDepo.ekle(kat3);

    // Ürünler
    auto urun1 = make_shared<Urun>(1, "iPhone 15", "Apple akıllı telefon", 45000.0, 50, 2);
    auto urun2 = make_shared<Urun>(2, "MacBook Pro", "Apple dizüstü bilgisayar", 75000.0, 30, 3);
    auto urun3 = make_shared<Urun>(3, "Samsung S24", "Samsung akıllı telefon", 35000.0, 40, 2);
    urunDepo.ekle(urun1);
    urunDepo.ekle(urun2);
    urunDepo.ekle(urun3);

    // Müşteriler
    auto musteri1 = make_shared<Musteri>(1, "ali@email.com", "Ali Yılmaz", "0555-111-1111", "2024-01-01");
    auto musteri2 = make_shared<Musteri>(2, "ayse@email.com", "Ayşe Kaya", "0532-222-2222", "2024-02-15");
    musteriDepo.ekle(musteri1);
    musteriDepo.ekle(musteri2);

    // Adresler
    auto adres1 = make_shared<Adres>(1, 1, "Ev", "İstanbul", "Kadıköy", "Caferağa", "No: 15", "34710");
    adresDepo.ekle(adres1);

    cout << endl;

    // 4. Servis işlemlerini test et
    cout << "[4] Servis işlemleri test ediliyor..." << endl << endl;

    try {
        cout << "  > siparisOlustur(musteri_id=1, adres_id=1) çağrılıyor..." << endl;
        int siparis_id = eticaret.siparisOlustur(1, 1);
        cout << "    ✓ Sipariş oluşturuldu! (ID: " << siparis_id << ")" << endl << endl;

        cout << "  > sipariseUrunEkle(siparis_id=" << siparis_id << ", urun_id=1, miktar=2) çağrılıyor..." << endl;
        eticaret.sipariseUrunEkle(siparis_id, 1, 2);
        auto siparis = siparisDepo.getir(siparis_id);
        cout << "    ✓ Ürün eklendi! Toplam tutar: " << siparis->get_toplam_tutar() << " TL" << endl << endl;

        cout << "  > siparisOnayla(siparis_id=" << siparis_id << ") çağrılıyor..." << endl;
        eticaret.siparisOnayla(siparis_id);
        siparis = siparisDepo.getir(siparis_id);
        cout << "    ✓ Sipariş onaylandı! Durum: " << siparis->get_durum() << endl;
        auto urun_check = urunDepo.getir(1);
        cout << "    ✓ Stok güncellendi! iPhone 15 yeni stok: " << urun_check->get_stok() << endl << endl;

        cout << "  > odemeAl(siparis_id=" << siparis_id << ", 'KrediKarti', 90000) çağrılıyor..." << endl;
        eticaret.odemeAl(siparis_id, "KrediKarti", 90000.0);
        cout << "    ✓ Ödeme alındı!" << endl << endl;

        cout << "  > musteriSiparisGecmisi(musteri_id=1) çağrılıyor..." << endl;
        auto gecmis = eticaret.musteriSiparisGecmisi(1);
        cout << "    ✓ Müşterinin " << gecmis.size() << " adet siparişi bulundu:" << endl;
        for (const auto& s : gecmis) {
            cout << "      - Sipariş #" << s->get_id() << ": " << s->get_durum() 
                 << ", Tutar: " << s->get_toplam_tutar() << " TL" << endl;
        }
        cout << endl;

        cout << "  > kategoriUrunleri(kategori_id=2) çağrılıyor..." << endl;
        auto urunler = eticaret.kategoriUrunleri(2);
        cout << "    ✓ Telefon kategorisinde " << urunler.size() << " adet ürün bulundu:" << endl;
        for (const auto& u : urunler) {
            cout << "      - " << u->get_ad() << ": " << u->get_fiyat() 
                 << " TL (Stok: " << u->get_stok() << ")" << endl;
        }
        cout << endl;

        cout << "  > enCokSatanUrunler(5) çağrılıyor..." << endl;
        auto populer = eticaret.enCokSatanUrunler(5);
        cout << "    ✓ En çok satan " << populer.size() << " ürün listelendi:" << endl;
        for (const auto& u : populer) {
            cout << "      - " << u->get_ad() << ": " << u->get_fiyat() << " TL" << endl;
        }

    } catch (const exception& e) {
        cerr << "HATA: " << e.what() << endl;
    }

    cout << endl;

    // 5. Özet
    cout << "[5] Sistem Özeti:" << endl;
    cout << "  - Toplam Kategori: " << kategoriDepo.boyut() << endl;
    cout << "  - Toplam Ürün: " << urunDepo.boyut() << endl;
    cout << "  - Toplam Müşteri: " << musteriDepo.boyut() << endl;
    cout << "  - Toplam Sipariş: " << siparisDepo.boyut() << endl;
    cout << endl;

    cout << "=== PROGRAM SONU ===" << endl;
    return 0;
}
