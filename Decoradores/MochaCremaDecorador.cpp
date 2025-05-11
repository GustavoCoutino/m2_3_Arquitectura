#include "MochaCremaDecorador.h"
#include <string>

// Mocha
Mocha::Mocha(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string Mocha::getDescripcion() const {
    return bebida->getDescripcion() + ", mocha";
}

double Mocha::getCosto() const {
    return bebida->getCosto() + 0.50;
}

// Crema
Crema::Crema(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string Crema::getDescripcion() const {
    return bebida->getDescripcion() + ", crema";
}

double Crema::getCosto() const {
    return bebida->getCosto() + 0.50;
}