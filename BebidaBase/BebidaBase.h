#pragma once
#include <string>
#include "../Bebida.h"

// HouseBlend - bebida base
class HouseBlend : public Bebida {
public:
    HouseBlend();
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// DarkRoast - bebida base
class DarkRoast : public Bebida {
public:
    DarkRoast();
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Espresso - bebida base
class Espresso : public Bebida {
public:
    Espresso();
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Decaf - bebida base
class Decaf : public Bebida {
public:
    Decaf();
    std::string getDescripcion() const override;
    double getCosto() const override;
};