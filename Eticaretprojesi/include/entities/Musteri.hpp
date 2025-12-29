#ifndef MUSTERI_HPP
#define MUSTERI_HPP

#include <string>

class Musteri {
private:
    int id;
    std::string email;
    std::string ad_soyad;
    std::string telefon;
    std::string kayit_tarihi;

public:
    Musteri();
    Musteri(int id, const std::string& email, const std::string& ad_soyad,
            const std::string& telefon, const std::string& kayit_tarihi);
    Musteri(const Musteri& other);
    ~Musteri();
    int get_id() const;
};

#endif // MUSTERI_HPP
