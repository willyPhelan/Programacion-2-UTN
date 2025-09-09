#pragma once
#include <string>
#include "Animal.h" //  se incluye la direccion de la clase de la cual se hereda


class Perro: public Animal{ // la clase Perro hereda de Animal las props y metodos de manera publica para poder manipularlos. // eso no significa que cambie el modificador de acceso privare en Animal

public:
    Perro();  // constructor por defecto
    Perro(std::string nombre, int edad, std::string _raza); // constructor con parámetros

    void ladrar();

private:

    std::string _raza ;
};
