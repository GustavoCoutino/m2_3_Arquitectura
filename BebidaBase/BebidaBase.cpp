#include "./BebidaBase.h"

// HouseBlend
HouseBlend::HouseBlend() {
    descripcion = "House Blend Coffee";
}

std::string HouseBlend::getDescripcion() const {
    return descripcion;
}

double HouseBlend::getCosto() const {
    return 1.0;
}

// DarkRoast
DarkRoast::DarkRoast() {
    descripcion = "Dark Roast Coffee";
}

std::string DarkRoast::getDescripcion() const {
    return descripcion;
}

double DarkRoast::getCosto() const {
    return 1.0;
}

// Espresso
Espresso::Espresso() {
    descripcion = "Espresso";
}

std::string Espresso::getDescripcion() const {
    return descripcion;
}

double Espresso::getCosto() const {
    return 1.5;
}

// Decaf
Decaf::Decaf() {
    descripcion = "Decaf Coffee";
}

std::string Decaf::getDescripcion() const {
    return descripcion;
}

double Decaf::getCosto() const {
    return 2.0;
}