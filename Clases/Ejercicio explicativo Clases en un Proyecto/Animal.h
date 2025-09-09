// en el archivo .h tendremos las declaraciones de la clase

#pragma once
#include <string>

// en los .h no se debe utilizar using namespace std /// se copia al crear a cada uno de los animales ocupando gran cantidad de espacio
// en .h al utilizar string usamos std::string

class Animal {

    private:

        int _edad ;
        std::string _nombre ;


        public:

         Animal() ; // constructor por defecto
         Animal(std::string _nombre, int _edad); // constructor con parametros
         int getEdad() ;
         void setEdad(int edad) ;
         std::string getNombre() ;
         void setNombre(std::string nombre) ;






};
