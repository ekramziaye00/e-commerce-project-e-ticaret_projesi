#ifndef URUN_HPP
#define URUN_HPP

#include <string>

class Urun {
private:
    int id;
    std::string ad;
    std::string aciklama;
    double fiyat;
    int stok;
    int kategori_id;

public:
    Urun();
    Urun(int id, const std::string& ad, const std::string& aciklama,
         double fiyat, int stok, int kategori_id);
    Urun(const Urun& other);
    ~Urun();
    int get_id() const;
    
    std::string get_ad() const;
    std::string get_aciklama() const;
    double get_fiyat() const;
    int get_stok() const;
    int get_kategori_id() const;
    void set_stok(int yeni_stok);
};

#endif // URUN_HPP
