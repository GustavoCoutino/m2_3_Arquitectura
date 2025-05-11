#include "Bebida.h"

Bebida::Bebida() : descripcion("Bebida desconocida") {}

std::string Bebida::getDescripcion() const {
    return descripcion;
}