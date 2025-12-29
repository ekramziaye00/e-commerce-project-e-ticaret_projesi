#ifndef SIPARIS_HPP
#define SIPARIS_HPP

#include <string>

class Siparis {
private:
    int id;
    int musteri_id;
    int adres_id;
    std::string tarih;
    std::string durum;
    double toplam_tutar;

public:
    Siparis();
    Siparis(int id, int musteri_id, int adres_id, const std::string& tarih,
            const std::string& durum, double toplam_tutar = 0.0);
    Siparis(const Siparis& other);
    ~Siparis();
    int get_id() const;
    
    int get_musteri_id() const;
    int get_adres_id() const;
    std::string get_tarih() const;
    std::string get_durum() const;
    double get_toplam_tutar() const;
    void set_durum(const std::string& yeni_durum);
    void set_toplam_tutar(double tutar);
};

#endif // SIPARIS_HPP
