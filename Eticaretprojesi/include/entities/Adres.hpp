#ifndef ADRES_HPP
#define ADRES_HPP

#include <string>

class Adres {
private:
    int id;
    int musteri_id;
    std::string baslik;
    std::string il;
    std::string ilce;
    std::string mahalle;
    std::string detay;
    std::string posta_kodu;

public:
    Adres();
    Adres(int id, int musteri_id, const std::string& baslik, const std::string& il,
          const std::string& ilce, const std::string& mahalle,
          const std::string& detay, const std::string& posta_kodu);
    Adres(const Adres& other);
    ~Adres();
    int get_id() const;
};

#endif // ADRES_HPP
