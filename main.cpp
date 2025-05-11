#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include "./BebidaBase/BebidaBase.h"
#include "./Decoradores/MochaCremaDecorador.h"
#include "./Decoradores/LecheDecorador.h"

void mostrarMenu() {
    std::cout << "\n========== COFFEE SHOP ==========" << std::endl;
    std::cout << "1. House Blend         $1.00" << std::endl;
    std::cout << "2. Dark Roast          $1.00" << std::endl;
    std::cout << "3. Espresso            $1.50" << std::endl;
    std::cout << "4. Decaf               $2.00" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Seleccione una bebida: ";
}

void mostrarMenuDecoradores() {
    std::cout << "\n¿Desea agregar algo extra?" << std::endl;
    std::cout << "1. Leche Entera             $0.30" << std::endl;
    std::cout << "2. Leche Light              $0.30" << std::endl;
    std::cout << "3. Leche Deslactosada       $0.30" << std::endl;
    std::cout << "4. Leche Deslactosada Light $0.30" << std::endl;
    std::cout << "5. Leche Soya               $0.30" << std::endl;
    std::cout << "6. Mocha                    $0.50" << std::endl;
    std::cout << "7. Crema                    $0.50" << std::endl;
    std::cout << "0. No agregar más" << std::endl;
    std::cout << "Seleccione: ";
}

Bebida* crearBebidaBase(int opcion) {
    switch(opcion) {
        case 1:
            return new HouseBlend();
        case 2:
            return new DarkRoast();
        case 3:
            return new Espresso();
        case 4:
            return new Decaf();
        default:
            return nullptr;
    }
}

Bebida* agregarDecorador(Bebida* bebida, int opcion) {
    switch(opcion) {
        case 1:
            return new LecheEntera(bebida);
        case 2:
            return new LecheLight(bebida);
        case 3:
            return new LecheDeslactosada(bebida);
        case 4:
            return new LecheDeslactosadaLight(bebida);
        case 5:
            return new LecheSoya(bebida);
        case 6:
            return new Mocha(bebida);
        case 7:
            return new Crema(bebida);
        default:
            return bebida;
    }
}


int main(){
    int opcionBebida, opcionDecorador;
    std::cout << "¡Bienvenido a Coffee Shop!" << std::endl;

    while(true){
        mostrarMenu();
        std::cin >> opcionBebida;

        if(opcionBebida == 0) {
            std::cout << "\n¡Gracias por su visita!" << std::endl;
            break;
        }

        Bebida *miBebida = crearBebidaBase(opcionBebida);
        if(miBebida == nullptr) {
            std::cout << "\nOpción no válida. Por favor intente de nuevo." << std::endl;
            continue;
        }

        // Mostrar la bebida base
        std::cout << "\nBebida seleccionada: " << miBebida->getDescripcion() << std::endl;
        std::cout << "Precio actual: $" << std::fixed << std::setprecision(2) << miBebida->getCosto() << std::endl;


        // Agregar decoradores
        do {
            mostrarMenuDecoradores();
            std::cin >> opcionDecorador;
            
            if(opcionDecorador != 0) {
                miBebida = agregarDecorador(miBebida, opcionDecorador);
                std::cout << "\nActualizado: " << miBebida->getDescripcion() << std::endl;
                std::cout << "Precio actual: $" << std::fixed << std::setprecision(2) 
                          << miBebida->getCosto() << std::endl;
            }
        } while(opcionDecorador != 0);

        // Mostrar orden final
        std::cout << "\n========== ORDEN FINAL ==========" << std::endl;
        std::cout << "Bebida: " << miBebida->getDescripcion() << std::endl;
        std::cout << "Precio Total: $" << std::fixed << std::setprecision(2) 
                  << miBebida->getCosto() << std::endl;
        std::cout << "=================================" << std::endl;
        
        // Limpiar memoria
        delete miBebida;
        
        std::cout << "\n¿Desea ordenar otra bebida? (s/n): ";
        char continuar;
        std::cin >> continuar;
        
        if(continuar != 's' && continuar != 'S') {
            std::cout << "\n¡Gracias por su visita!" << std::endl;
            break;
        }
    }
}