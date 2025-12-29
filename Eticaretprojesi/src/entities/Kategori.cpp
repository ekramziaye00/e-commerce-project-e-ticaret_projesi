#include "entities/Kategori.hpp"

Kategori::Kategori() : id(0), ad(""), ust_kategori_id(0) {
}

Kategori::Kategori(int id, const std::string& ad, int ust_kategori_id)
    : id(id), ad(ad), ust_kategori_id(ust_kategori_id) {
}

Kategori::Kategori(const Kategori& other)
    : id(other.id), ad(other.ad), ust_kategori_id(other.ust_kategori_id) {
}

Kategori::~Kategori() {
}

int Kategori::get_id() const {
    return id;
}
