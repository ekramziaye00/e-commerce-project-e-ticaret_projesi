#include "entities/Adres.hpp"

Adres::Adres() : id(0), musteri_id(0), baslik(""), il(""), ilce(""), mahalle(""), detay(""), posta_kodu("") {
}

Adres::Adres(int id, int musteri_id, const std::string& baslik, const std::string& il,
      const std::string& ilce, const std::string& mahalle,
      const std::string& detay, const std::string& posta_kodu)
    : id(id), musteri_id(musteri_id), baslik(baslik), il(il), ilce(ilce),
      mahalle(mahalle), detay(detay), posta_kodu(posta_kodu) {
}

Adres::Adres(const Adres& other)
    : id(other.id), musteri_id(other.musteri_id), baslik(other.baslik), il(other.il),
      ilce(other.ilce), mahalle(other.mahalle), detay(other.detay), posta_kodu(other.posta_kodu) {
}

Adres::~Adres() {
}

int Adres::get_id() const {
    return id;
}
