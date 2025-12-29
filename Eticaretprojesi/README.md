# E-Commerce Order Management System

A modern e-commerce order management system built with C++ following multi-layered architecture principles (3-tier architecture).

## Features

- **Customer Management**: Register customers with complete profile information
- **Product Catalog**: Hierarchical category structure with product management
- **Order Processing**: Complete order lifecycle from creation to fulfillment
- **Payment Processing**: Multiple payment methods support
- **Inventory Management**: Real-time stock tracking and updates
- **Analytics**: Sales reporting and product popularity tracking

## Architecture

The system follows a clean **3-tier architecture**:

```
┌─────────────────────────────────┐
│     Presentation Layer          │
│         (main.cpp)              │
└────────────┬────────────────────┘
             │
┌────────────▼────────────────────┐
│     Business Logic Layer        │
│    (ETicaretServisi.cpp)        │
└────────────┬────────────────────┘
             │
┌────────────▼────────────────────┐
│      Data Access Layer          │
│      (Depo<T> Template)         │
└─────────────────────────────────┘
```

## Entity Model

### Core Entities

- **Musteri** (Customer): User account and profile information
- **Adres** (Address): Delivery addresses linked to customers
- **Kategori** (Category): Hierarchical product categorization
- **Urun** (Product): Product catalog with pricing and inventory
- **Siparis** (Order): Customer orders with status tracking
- **SiparisKalemi** (Order Item): Individual items within orders
- **Odeme** (Payment): Payment transactions and records

### Entity Relationships

```
Musteri (1) ────< (n) Adres
Musteri (1) ────< (n) Siparis
Kategori (1) ───< (n) Urun
Siparis (1) ────< (n) SiparisKalemi
Urun (1) ───────< (n) SiparisKalemi
Siparis (1) ────< (1) Odeme
```

## API Services

The system provides 11 core service operations:

| Service | Description |
|---------|-------------|
| `musteriKaydet()` | Register new customer |
| `urunEkle()` | Add new product to catalog |
| `siparisOlustur()` | Create new order |
| `sipariseUrunEkle()` | Add product to order |
| `siparisOnayla()` | Confirm order and update inventory |
| `siparisIptalEt()` | Cancel order |
| `odemeAl()` | Process payment |
| `stokGuncelle()` | Update product stock |
| `musteriSiparisGecmisi()` | Get customer order history |
| `kategoriUrunleri()` | Get products by category |
| `enCokSatanUrunler()` | Get best-selling products |

## Technologies

- **Language**: C++17
- **Build System**: CMake
- **Design Patterns**: Repository Pattern, Template-based Generic Repository
- **Architecture**: 3-Tier Architecture (Presentation, Business Logic, Data Access)

## Build & Run

### Prerequisites
- C++ compiler with C++17 support (GCC, Clang, or MSVC)
- CMake 3.10 or higher

### Building the Project

```bash
# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Compile
make

# Run the application
./eticaret_siparis
```

## Project Structure

```
.
├── CMakeLists.txt
├── include/
│   ├── entities/          # Entity classes
│   │   ├── Musteri.hpp
│   │   ├── Adres.hpp
│   │   ├── Kategori.hpp
│   │   ├── Urun.hpp
│   │   ├── Siparis.hpp
│   │   ├── SiparisKalemi.hpp
│   │   └── Odeme.hpp
│   ├── repositories/      # Data access layer
│   │   └── Depo.hpp
│   └── services/          # Business logic layer
│       └── ETicaretServisi.hpp
├── src/
│   ├── entities/          # Entity implementations
│   ├── services/          # Service implementations
│   ├── utils/             # Utility functions
│   └── main.cpp           # Application entry point
└── README.md
```

## Example Output

```
=== E-TİCARET SİPARİŞ SİSTEMİ ===
Çok Katmanlı Mimari Projesi
=================================

[1] Depolar oluşturuluyor...
[2] Servis oluşturuluyor...
[3] Örnek veriler yükleniyor...

[4] Servis işlemleri test ediliyor...

  > siparisOlustur(musteri_id=1, adres_id=1) çağrılıyor...
    ✓ Sipariş oluşturuldu! (ID: 1)

  > sipariseUrunEkle(siparis_id=1, urun_id=1, miktar=2) çağrılıyor...
    ✓ Ürün eklendi! Toplam tutar: 90000 TL

  > siparisOnayla(siparis_id=1) çağrılıyor...
    ✓ Sipariş onaylandı! Durum: Onaylandi
    ✓ Stok güncellendi! iPhone 15 yeni stok: 48

[5] Sistem Özeti:
  - Toplam Kategori: 3
  - Toplam Ürün: 3
  - Toplam Müşteri: 2
  - Toplam Sipariş: 1
```

## License

MIT License - feel free to use this project for learning and development purposes.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
