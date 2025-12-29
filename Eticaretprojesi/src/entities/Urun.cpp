#include "entities/Urun.hpp"

Urun::Urun() : id(0), ad(""), aciklama(""), fiyat(0.0), stok(0), kategori_id(0) {
}

Urun::Urun(int id, const std::string& ad, const std::string& aciklama,
     double fiyat, int stok, int kategori_id)
    : id(id), ad(ad), aciklama(aciklama), fiyat(fiyat), stok(stok), kategori_id(kategori_id) {
}

Urun::Urun(const Urun& other)
    : id(other.id), ad(other.ad), aciklama(other.aciklama),
      fiyat(other.fiyat), stok(other.stok), kategori_id(other.kategori_id) {
}

Urun::~Urun() {
}

int Urun::get_id() const {
    return id;
}

std::string Urun::get_ad() const {
    return ad;
}

std::string Urun::get_aciklama() const {
    return aciklama;
}

double Urun::get_fiyat() const {
    return fiyat;
}

int Urun::get_stok() const {
    return stok;
}

int Urun::get_kategori_id() const {
    return kategori_id;
}

void Urun::set_stok(int yeni_stok) {
    stok = yeni_stok;
}
