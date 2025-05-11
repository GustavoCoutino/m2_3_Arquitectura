#include "LecheDecorador.h"
#include <string>

// Leche Entera
LecheEntera::LecheEntera(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string LecheEntera::getDescripcion() const {
    return bebida->getDescripcion() + ", leche entera";
}

double LecheEntera::getCosto() const {
    return bebida->getCosto() + 0.30;
}

// Leche Light
LecheLight::LecheLight(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string LecheLight::getDescripcion() const {
    return bebida->getDescripcion() + ", leche light";
}

double LecheLight::getCosto() const {
    return bebida->getCosto() + 0.30;
}

// Leche Deslactosada
LecheDeslactosada::LecheDeslactosada(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string LecheDeslactosada::getDescripcion() const {
    return bebida->getDescripcion() + ", leche deslactosada";
}

double LecheDeslactosada::getCosto() const {
    return bebida->getCosto() + 0.30;
}

// Leche Deslactosada Light
LecheDeslactosadaLight::LecheDeslactosadaLight(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string LecheDeslactosadaLight::getDescripcion() const {
    return bebida->getDescripcion() + ", leche deslactosada light";
}

double LecheDeslactosadaLight::getCosto() const {
    return bebida->getCosto() + 0.30;
}

// Leche Soya
LecheSoya::LecheSoya(Bebida *bebida) : CondimentoDecorador(bebida) {
}

std::string LecheSoya::getDescripcion() const {
    return bebida->getDescripcion() + ", leche soya";
}

double LecheSoya::getCosto() const {
    return bebida->getCosto() + 0.30;
}