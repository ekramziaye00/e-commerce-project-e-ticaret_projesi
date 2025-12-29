cmake_minimum_required(VERSION 3.15)
project(ETicaretSiparis LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(ENTITY_SOURCES
    src/entities/Musteri.cpp
    src/entities/Adres.cpp
    src/entities/Kategori.cpp
    src/entities/Urun.cpp
    src/entities/Siparis.cpp
    src/entities/SiparisKalemi.cpp
    src/entities/Odeme.cpp
)

set(SOURCES
    src/main.cpp
    ${ENTITY_SOURCES}
    src/services/ETicaretServisi.cpp
)

add_executable(eticaret_siparis ${SOURCES})

target_compile_options(eticaret_siparis PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -Wpedantic>
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
)
