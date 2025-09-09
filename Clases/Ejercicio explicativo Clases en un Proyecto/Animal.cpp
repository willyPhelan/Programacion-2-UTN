// En el archivo .cpp tenemos las implementaciones de las funciones de la clase

#include "Animal.h"

using namespace std ;

Animal::Animal() // constructor con porps por defecto

: _edad(0), _nombre("Sin nombre") { // lista de inicializacion // parametros por defecto

   /* _edad = 0 ;
    _nombre = "Sin nombre" ; */
}

Animal::Animal(std::string nombre, int edad) // constructor con props pasadas por parametros

: Animal :: Animal() { // lista de inicializacion // parametros por defecto



    setEdad(edad) ;
    setNombre(nombre) ; }

int Animal::getEdad(){

    return _edad ;
}

void Animal::setEdad(int edad){

    if(edad >= 0){ _edad = edad  ; }

}

std::string Animal::getNombre(){
    return _nombre ;
}

void Animal::setNombre(std::string nombre){

 _nombre = nombre;} ;
