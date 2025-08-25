/*
5
Una tienda online dispone de todas las ventas realizadas el mes pasado en los tres pa�ses donde comercializa. Por cada venta registra:
N�mero de pa�s (1 a 3)
D�a de la venta (1 a 31)
Monto de la venta (float)

Para indicar el fin de la carga de informaci�n se ingresa un n�mero de pa�s igual a -1. La informaci�n no se encuentra agrupada ni ordenada bajo ning�n criterio.
Se pide calcular e informar:

A) Por cada pa�s y d�a, el total recaudado. S�lo mostrar informaci�n de aquellos d�as en los que hubo recaudaci�n.
B) Por cada pa�s, la cantidad de d�as en los que no hubo recaudaci�n.
C) Los n�meros de d�a en los que no hubo recaudaci�n en ninguno de los pa�ses.

*/

#include "funciones.h"
#include <iostream>


using namespace std ;


int main(){

    int opc ;

    float paisesDias[3][31]={} ;  // matriz inicializada en 0

    while(true){

        system("cls") ;

        cout << "REGISTROS TIENDA ONLINE" << endl ;

        cout << "*********************************************" << endl ;
        cout << "1. Ingresar datos" << endl ;
        cout << "2. Recaudacion por pais y dia" << endl ;
        cout << "3. Dias sin recaudacion por pais" << endl ;
        cout << "4. Dias sin recaudacion general" << endl ;
        cout << "0. Fin del programa" << endl ;
        cout << "*********************************************" << endl ;
        cout << "Elegir opcion: " << endl ;

        cin >> opc ;

        system("cls") ;

        switch(opc){

            case 1: ingresarDatos(paisesDias) ;

            break ;

            case 2: recaudacionPaisDia(paisesDias, 3, 31)  ; // 3 y 31 corresponden a las filas y columnas de la matriz

            break ;

            case 3: diasPaisSinRecaudacion(paisesDias, 3, 31) ;

            break ;

            case 4: diasSinRecaudacion(paisesDias, 3, 31) ;

            case 0: return 0 ;

            break ;

            default: cout << "Ingreso incorrecto" << endl ;

            }

            cout << endl ;

            system("pause") ;

    }

    system("pause") ;

    return 0 ;
}


