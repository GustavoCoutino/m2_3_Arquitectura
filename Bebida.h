#pragma once
#include <string>

// Clase componente base
class Bebida {
public:
    Bebida();
    virtual ~Bebida() = default;

    // Devuelve la descripción de la bebida
    virtual std::string getDescripcion() const;
    // Método abstracto para obtener el costo
    virtual double getCosto() const = 0;

protected:
    std::string descripcion;
};