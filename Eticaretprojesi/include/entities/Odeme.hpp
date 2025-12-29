#ifndef ODEME_HPP
#define ODEME_HPP

#include <string>

class Odeme {
private:
    int id;
    int siparis_id;
    std::string yontem;
    double tutar;
    std::string tarih;
    std::string durum;

public:
    Odeme();
    Odeme(int id, int siparis_id, const std::string& yontem, double tutar,
          const std::string& tarih, const std::string& durum);
    Odeme(const Odeme& other);
    ~Odeme();
    int get_id() const;
};

#endif // ODEME_HPP
