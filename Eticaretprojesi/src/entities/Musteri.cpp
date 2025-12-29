#include "entities/Musteri.hpp"

Musteri::Musteri() : id(0), email(""), ad_soyad(""), telefon(""), kayit_tarihi("") {
}

Musteri::Musteri(int id, const std::string& email, const std::string& ad_soyad,
        const std::string& telefon, const std::string& kayit_tarihi)
    : id(id), email(email), ad_soyad(ad_soyad), telefon(telefon), kayit_tarihi(kayit_tarihi) {
}

Musteri::Musteri(const Musteri& other)
    : id(other.id), email(other.email), ad_soyad(other.ad_soyad),
      telefon(other.telefon), kayit_tarihi(other.kayit_tarihi) {
}

Musteri::~Musteri() {
}

int Musteri::get_id() const {
    return id;
}
