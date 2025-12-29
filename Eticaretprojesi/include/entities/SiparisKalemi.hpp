#ifndef SIPARIS_KALEMI_HPP
#define SIPARIS_KALEMI_HPP

class SiparisKalemi {
private:
    int id;
    int siparis_id;
    int urun_id;
    int miktar;
    double birim_fiyat;

public:
    SiparisKalemi();
    SiparisKalemi(int id, int siparis_id, int urun_id, int miktar, double birim_fiyat);
    SiparisKalemi(const SiparisKalemi& other);
    ~SiparisKalemi();
    int get_id() const;
    
    int get_siparis_id() const;
    int get_urun_id() const;
    int get_miktar() const;
    double get_birim_fiyat() const;
};

#endif // SIPARIS_KALEMI_HPP
