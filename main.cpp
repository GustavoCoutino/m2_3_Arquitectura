#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <vector>
#include <algorithm>
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

std::string obtenerNombreCondimento(int opcion) {
    switch(opcion) {
        case 1: return "leche entera";
        case 2: return "leche light";
        case 3: return "leche deslactosada";
        case 4: return "leche deslactosada light";
        case 5: return "mocha";
        case 6: return "leche soya";
        case 7: return "crema";
        default: return "";
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
                std::string descripcionTemp = miBebida->getDescripcion();
                
                // Verificar si el condimento a agregar ya existe antes de añadirlo
                bool esRepetido = false;
                if (descripcionTemp.find(',') != std::string::npos) {
                    // Obtener el nombre del condimento que se va a agregar
                    std::string nuevoCondimento = obtenerNombreCondimento(opcionDecorador);
                    
                    // Buscar si ya existe
                    std::string descripcionCondimentos = descripcionTemp.substr(descripcionTemp.find(',') + 1);
                    std::stringstream ss(descripcionCondimentos);
                    std::string condimento;
                    
                    while (std::getline(ss, condimento, ',')) {
                        condimento.erase(0, condimento.find_first_not_of(" "));
                        condimento.erase(condimento.find_last_not_of(" ") + 1);
                        
                        if (condimento == nuevoCondimento) {
                            esRepetido = true;
                            break;
                        }
                    }
                }
                
                if (esRepetido) {
                    std::cout << "\n¡Este condimento ya está en la bebida!" << std::endl;
                    std::cout << "Descripción actual: " << miBebida->getDescripcion() << std::endl;
                    std::cout << "Precio actual: $" << std::fixed << std::setprecision(2) 
                              << miBebida->getCosto() << std::endl;
                } else {
                    // Agregar el decorador solo si no es repetido
                    miBebida = agregarDecorador(miBebida, opcionDecorador);
                    
                    if(miBebida->getDescripcion() == descripcionTemp){
                        std::cout << "\nOpción no válida. Por favor intente de nuevo." << std::endl;
                    } else {
                        std::cout << "\nActualizado: " << miBebida->getDescripcion() << std::endl;
                        std::cout << "Precio actual: $" << std::fixed << std::setprecision(2) 
                                  << miBebida->getCosto() << std::endl;
                    }
                }
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