#include "entities/Siparis.hpp"

Siparis::Siparis() : id(0), musteri_id(0), adres_id(0), tarih(""), durum(""), toplam_tutar(0.0) {
}

Siparis::Siparis(int id, int musteri_id, int adres_id, const std::string& tarih,
        const std::string& durum, double toplam_tutar)
    : id(id), musteri_id(musteri_id), adres_id(adres_id), tarih(tarih),
      durum(durum), toplam_tutar(toplam_tutar) {
}

Siparis::Siparis(const Siparis& other)
    : id(other.id), musteri_id(other.musteri_id), adres_id(other.adres_id),
      tarih(other.tarih), durum(other.durum), toplam_tutar(other.toplam_tutar) {
}

Siparis::~Siparis() {
}

int Siparis::get_id() const {
    return id;
}

int Siparis::get_musteri_id() const {
    return musteri_id;
}

int Siparis::get_adres_id() const {
    return adres_id;
}

std::string Siparis::get_tarih() const {
    return tarih;
}

std::string Siparis::get_durum() const {
    return durum;
}

double Siparis::get_toplam_tutar() const {
    return toplam_tutar;
}

void Siparis::set_durum(const std::string& yeni_durum) {
    durum = yeni_durum;
}

void Siparis::set_toplam_tutar(double tutar) {
    toplam_tutar = tutar;
}
