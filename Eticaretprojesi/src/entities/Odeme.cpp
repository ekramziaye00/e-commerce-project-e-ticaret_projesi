#include "entities/Odeme.hpp"

Odeme::Odeme() : id(0), siparis_id(0), yontem(""), tutar(0.0), tarih(""), durum("") {
}

Odeme::Odeme(int id, int siparis_id, const std::string& yontem, double tutar,
      const std::string& tarih, const std::string& durum)
    : id(id), siparis_id(siparis_id), yontem(yontem), tutar(tutar), tarih(tarih), durum(durum) {
}

Odeme::Odeme(const Odeme& other)
    : id(other.id), siparis_id(other.siparis_id), yontem(other.yontem),
      tutar(other.tutar), tarih(other.tarih), durum(other.durum) {
}

Odeme::~Odeme() {
}

int Odeme::get_id() const {
    return id;
}
