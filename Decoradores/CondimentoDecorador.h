#pragma once
#include "../Bebida.h"

class CondimentoDecorador : public Bebida {
public:
    CondimentoDecorador(Bebida *bebida);
    virtual ~CondimentoDecorador();

    // Los decoradores concretos deben implementar estos métodos
    virtual std::string getDescripcion() const override = 0;
    virtual double getCosto() const override = 0;
    
protected:
    Bebida *bebida;
};
