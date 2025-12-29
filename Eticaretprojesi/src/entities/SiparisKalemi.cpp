#include "entities/SiparisKalemi.hpp"

SiparisKalemi::SiparisKalemi() : id(0), siparis_id(0), urun_id(0), miktar(0), birim_fiyat(0.0) {
}

SiparisKalemi::SiparisKalemi(int id, int siparis_id, int urun_id, int miktar, double birim_fiyat)
    : id(id), siparis_id(siparis_id), urun_id(urun_id), miktar(miktar), birim_fiyat(birim_fiyat) {
}

SiparisKalemi::SiparisKalemi(const SiparisKalemi& other)
    : id(other.id), siparis_id(other.siparis_id), urun_id(other.urun_id),
      miktar(other.miktar), birim_fiyat(other.birim_fiyat) {
}

SiparisKalemi::~SiparisKalemi() {
}

int SiparisKalemi::get_id() const {
    return id;
}

int SiparisKalemi::get_siparis_id() const {
    return siparis_id;
}

int SiparisKalemi::get_urun_id() const {
    return urun_id;
}

int SiparisKalemi::get_miktar() const {
    return miktar;
}

double SiparisKalemi::get_birim_fiyat() const {
    return birim_fiyat;
}
