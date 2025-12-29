#ifndef KATEGORI_HPP
#define KATEGORI_HPP

#include <string>

class Kategori {
private:
    int id;
    std::string ad;
    int ust_kategori_id;

public:
    Kategori();
    Kategori(int id, const std::string& ad, int ust_kategori_id = 0);
    Kategori(const Kategori& other);
    ~Kategori();
    int get_id() const;
};

#endif // KATEGORI_HPP
