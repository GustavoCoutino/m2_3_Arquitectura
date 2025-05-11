#include "CondimentoDecorador.h"

CondimentoDecorador::CondimentoDecorador(Bebida *bebida) : bebida(bebida) {
}

CondimentoDecorador::~CondimentoDecorador() {
    delete bebida;
}