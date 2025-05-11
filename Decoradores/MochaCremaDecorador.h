#pragma once
#include "CondimentoDecorador.h"

// Crema
class Crema : public CondimentoDecorador {
public:
    Crema(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Mocha
class Mocha : public CondimentoDecorador {
public:
    Mocha(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};
