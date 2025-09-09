#include <iostream>
#include "Perro.h"
#include "Gato.h"

using namespace std;

int main()
{
   Gato g ;

   Perro perro1, perro2("Mona", 2, "Chiuaua") ;

   perro1.ladrar() ;

   cout << "Nombre del perro: " << perro1.getNombre() << endl ;
   cout << "Nombre del perro: " << perro2.getNombre() << endl ;

    perro2.ladrar() ;

    cout << "Gato responde: " ;
    g.maullar() ;

   return 0 ;
}
