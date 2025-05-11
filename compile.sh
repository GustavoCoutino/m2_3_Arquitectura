echo "Compilando Coffee Shop..."

g++ -std=c++11 -o coffee_shop \
    main.cpp \
    Bebida.cpp \
    BebidaBase/BebidaBase.cpp \
    Decoradores/CondimentoDecorador.cpp \
    Decoradores/LecheDecorador.cpp \
    Decoradores/MochaCremaDecorador.cpp

if [ $? -eq 0 ]; then
    echo "Compilación exitosa!"
else
    echo "Error en la compilación"
fi