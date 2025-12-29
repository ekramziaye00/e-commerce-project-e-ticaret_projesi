#ifndef DEPO_HPP
#define DEPO_HPP

#include <vector>
#include <memory>
#include <functional>
#include <algorithm>
#include <stdexcept>

/**
 * @brief Şablonlu Depo (Repository) sınıfı
 *
 * Bu sınıf, veri erişim katmanını soyutlar ve CRUD operasyonları sağlar.
 * Defensive copy stratejisi ile veri tutarlılığı korunur.
 *
 * @tparam T Varlık türü (get_id() metoduna sahip olmalı)
 */
template <typename T>
class Depo {
public:
    using Ptr = std::shared_ptr<T>;
    using Elemanlar = std::vector<Ptr>;
    using AramaFonksiyonu = std::function<bool(const Ptr&)>;

private:
    Elemanlar _elemanlar;
    int _sonrakiId = 1;

public:
    /**
     * @brief Yeni eleman ekler
     * @param eleman Eklenecek eleman (shared_ptr)
     * @throws std::invalid_argument Eleman null ise
     */
    void ekle(const Ptr& eleman) {
        if (!eleman) {
            throw std::invalid_argument("Eleman null olamaz");
        }
        _elemanlar.push_back(eleman);
    }

    /**
     * @brief ID'ye göre eleman getirir
     * @param id Aranan ID
     * @return Bulunan elemanın kopyası (defensive copy)
     * @throws std::runtime_error Eleman bulunamazsa
     */
    Ptr getir(int id) const {
        for (const auto& eleman : _elemanlar) {
            if (eleman->get_id() == id) {
                return std::make_shared<T>(*eleman);
            }
        }
        throw std::runtime_error("Eleman bulunamadi");
    }

    /**
     * @brief Kritere göre arama yapar
     * @param kriter Lambda fonksiyonu
     * @return Kritere uyan elemanların listesi
     */
    Elemanlar ara(AramaFonksiyonu kriter) const {
        Elemanlar sonuc;
        for (const auto& eleman : _elemanlar) {
            if (kriter(eleman)) {
                sonuc.push_back(std::make_shared<T>(*eleman));
            }
        }
        return sonuc;
    }

    /**
     * @brief Elemanı günceller
     * @param yeniEleman Güncellenecek eleman
     * @throws std::runtime_error Eleman bulunamazsa
     */
    void guncelle(const Ptr& yeniEleman) {
        if (!yeniEleman) {
            throw std::invalid_argument("Eleman null olamaz");
        }
        for (auto& eleman : _elemanlar) {
            if (eleman->get_id() == yeniEleman->get_id()) {
                eleman = std::make_shared<T>(*yeniEleman);
                return;
            }
        }
        throw std::runtime_error("Eleman bulunamadi");
    }

    /**
     * @brief ID'ye göre eleman siler
     * @param id Silinecek elemanın ID'si
     * @throws std::runtime_error Eleman bulunamazsa
     */
    void sil(int id) {
        auto it = std::find_if(_elemanlar.begin(), _elemanlar.end(),
            [id](const Ptr& eleman) { return eleman->get_id() == id; });
        if (it != _elemanlar.end()) {
            _elemanlar.erase(it);
        } else {
            throw std::runtime_error("Eleman bulunamadi");
        }
    }

    /**
     * @brief Tüm elemanları döndürür
     * @return Tüm elemanların listesi (defensive copy)
     */
    Elemanlar tumunu() const {
        Elemanlar sonuc;
        for (const auto& eleman : _elemanlar) {
            sonuc.push_back(std::make_shared<T>(*eleman));
        }
        return sonuc;
    }

    /**
     * @brief Eleman sayısını döndürür
     */
    size_t boyut() const {
        return _elemanlar.size();
    }

    /**
     * @brief Iterator başlangıcı (range-based for desteği)
     */
    auto begin() { return _elemanlar.begin(); }
    auto begin() const { return _elemanlar.begin(); }

    /**
     * @brief Iterator sonu (range-based for desteği)
     */
    auto end() { return _elemanlar.end(); }
    auto end() const { return _elemanlar.end(); }
};

#endif // DEPO_HPP
