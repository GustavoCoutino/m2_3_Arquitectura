#pragma once
#include "CondimentoDecorador.h"

// Leche Entera
class LecheEntera : public CondimentoDecorador {
public:
    LecheEntera(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Leche Deslactosada
class LecheDeslactosada : public CondimentoDecorador {
public:
    LecheDeslactosada(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Leche Light
class LecheLight : public CondimentoDecorador {
public:
    LecheLight(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Leche Deslactosada Light
class LecheDeslactosadaLight : public CondimentoDecorador {
public:
    LecheDeslactosadaLight(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};

// Leche Soya
class LecheSoya : public CondimentoDecorador {
public:
    LecheSoya(Bebida *bebida);
    std::string getDescripcion() const override;
    double getCosto() const override;
};