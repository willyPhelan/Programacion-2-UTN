#include <iostream> // para el uso de cout
#include "Perro.h"

using namespace std ;

Perro::Perro() : Animal::Animal(), _raza("Sin raza") {}  // constructor por defecto //  _raza("Sin raza") forma de inicializar composiciones

Perro::Perro(string nombre, int edad, string raza) : Animal::Animal(nombre, edad), _raza(raza){} // despues del constructor Perro, llamamos al constructor de Animal (se hace desp de los : una lista de inicializacion)

// al invocar al constructor de perro, despuess debo invocar la consturctor de la clase padre Animal (Animal::Animal) -> sino paso parametros llamara al constructor sin parametros, si le agrgo parametros como en el ejemplo llamar al que recibe parametros

// si quiero agregar parametros que no estan en el consturctor lo hago luego de los parentesis
void Perro::ladrar() {

    cout << _raza << endl << "Woof Woof" << endl;
}
