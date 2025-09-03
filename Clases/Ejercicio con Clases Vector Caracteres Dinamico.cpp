#include <iostream>
#include <cstring> // libreria necesaria para utilizar los metodos strlen y strcpy

using namespace std ;


class Cadena {

    private: char *p ; // puntero para crear un vector de caracteres.
             int tam ;

    public:

        Cadena(const char *inicio) { // constructor // recibo vector de caracteres por parametro

            tam = strlen(inicio) +1 ;

            p = new char[tam] ;

            if(p == nullptr){exit(1) ; }

            strcpy(p, inicio) ; // copio al vector dinamico p el contenido del vector inicio recibido por parametro

            p[tam-1] = '\0' ; // asigno a la ultima posicion del vector de caracteres el terminador



        } ;

        // SETTER PARA MODIFICAR EL VALOR DE UNA PROP

        void setP(const char *nuevo){ // recibo un nuevo vector de caracteres

            delete [] p ; // borro el contenido viejo

            tam = strlen(nuevo) + 1 ;

            p = new char [tam] ;

            if (p == nullptr) exit(1) ;

            strcpy(p, nuevo) ; // copio el contenido del array nuevo en p

            p[tam -1] = '\0' ;


        }


        // SETTER que con el metodo toupper pone las letras en mayusc.

          void aMayusculas(){

                for (int i = 0 ; i < tam - 1 ; i++) {

                   p[i] = toupper(p[i]) ; }

                   cout << endl << p << " Y LO PUSE EN MAYUSCULAS" << endl ;

          }

        // agregar otro metodo que convierta todos los caracteres a minusculas

           void aMinusculas() {

                for (int i = 0 ; i < tam - 1 ; i++) {  // tam-1 para no tocar el '\0'

                    p[i] = tolower(p[i]) ; }

                    cout << endl << p << " y lo puse en minusculas" << endl ;


                    }

        // agregar otro metodo que ponga la primer letra en minuscula

        void primeraMinuscula() {

            if (tam > 1) {  // si la cadena no está vacía

            p[0] = tolower(p[0]) ;    // cambio a minusc. solo la primera letra

            }

            cout << endl << p << " (con primera letra en minuscula)" << endl ; }

            // int buscarCaracter(char aBuscar) que devuelva la posición de la  primera aparicion del
            // caracter aBuscar en la cadena. Si no lo encuentra que devuelva -1

          int buscarCaracter(char aBuscar) {

            for (int i = 0; i < tam - 1; i++) {

            if (p[i] == aBuscar) {

            cout << "El caracter '" << aBuscar << "' se encontro en la posicion: " << i << endl ;

            return i ;  // devuelvo la posición
        }
    }

    // Si no lo encuentra

    cout << "El caracter " << aBuscar << " no se encontro en la cadena." << endl ;
    return -1 ;
}




    // Getter

        void Mostrar(){ cout << endl << p << endl ; }

    // Destructor

    ~ Cadena() { delete [] p ; } // borro memoria en el destructor
} ;

int main() {

    Cadena palabra("Hola Mundo") ; // Cadena es la clase, palabra el objeto
    palabra.Mostrar() ; // mostrar es un metodo del objeto palabra, un getter

    system("pause") ;

    palabra.setP("Hola, cambie el valor mediante un SETTER") ;
    palabra.Mostrar() ;

    system("pause") ;

    palabra.aMayusculas() ;

    system("pause") ;

    palabra.aMinusculas() ;

    system("pause") ;

    palabra.primeraMinuscula() ;

    system("pause") ;

    palabra.buscarCaracter('m') ;

    return 0 ;


}
