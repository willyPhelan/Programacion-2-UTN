#include "funciones.h"
#include <iostream>

using namespace std ;

void ingresarDatos(float mat[][31]){

    int pais, dia ;
    float monto ;

    cout << "Ingresar el pais: " << endl ;
    cin >> pais ;

    while(pais != -1) {

        cout << "Ingresar el dia: " << endl ;
        cin >> dia ;

        cout << "Ingresar el monto de la venta: " << endl ;
        cin >> monto ;

        mat[pais -1][dia-1]+= monto ; // ingreso en la primera posicion de la matriz el primer monto asignado a ese pais

        cout << endl << "*********************************************" << endl ;

        cout << endl << "Ingresar un nuevo pais: " << endl ;
        cin >> pais ;
    }
}


void recaudacionPaisDia(float mat[][31], int filas, int columnas){

    cout << "RECAUDACION SEGUN EL PAIS: " << endl ;
    cout << "*********************************************" << endl ;

    for (int i = 0 ; i < filas ; i++){ // forma basica de recorrer una matriz, primero un FOR para recorrer filas y luego un FOR anidado para recorrer columnas

        cout << endl << "Pais: " << i + 1 << endl ; // EL  i + 1  y mas abajo el j + 1 es solo para mostrarle al usuario un número más natural (empezando en 1) en realidad es la posicion 0 de la matriz pero con el +1 se muestra como: / Para que muestre "País 1" en vez de "País 0"

        for(int j = 0 ; j < columnas ; j++){

            if(mat[i][j] != 0) { // va iterando en cada fila hasta llegar a la ultima columna buscando los dias que hubo ingresos

                cout << "Dia: " << j + 1 << endl << "Recaudacion: " << mat[i][j] << "\t" ;

                cout << endl << "*********************************************" << endl ;
            }
        }
    }
}

void diasPaisSinRecaudacion(float mat[][31], int filas, int columnas){

int cantSinVentas ;

for (int i = 0 ; i < filas ; i++){

        cantSinVentas = 0 ; // al finalizar cada recorido de fila (paises) vuelve el contador a 0 para empezar por otro pais reocrriendo cada uno de los dias

        cout << endl << "Pais: " << i + 1 << endl ;

        for(int j = 0 ; j < columnas ; j++){

            if(mat[i][j] == 0) {   // por cada dia que no haya ventas aumento el contador

                cantSinVentas++ ;


            }
        }


        cout << "Dias sin recaudacion por pais: " << cantSinVentas << endl ; // lo hago fuera del FOR cuando termino de recorrer los paises
        cout << endl ;

    }
}

void diasSinRecaudacion (float mat[][31], int filas, int columnas){ // tengo que calcular en este caso si algun dia no tuvo recaudacion en TODOS los paises (puedo utilizar un contador que a medida que el recorrido del FOR encuentre un dia vacio sume 1. Cuando el contador llegue a 3 significara que en ese dia no hubo recaudacion en ningun pais)

int cantSinVentas ;

for (int i = 0 ; i < columnas ; i++){ // invierto el recorrido del for para que primero recorra los dias(columnas) y luego los paises (filas)

        cantSinVentas = 0 ;

        for(int j = 0 ; j < filas ; j++){

        if(mat[j][i] == 0) {  // misma logica que la anterior

                cantSinVentas++ ;


            }
        }


        if(cantSinVentas == 3) { cout << "En el dia " << i + 1 << " no hubo ventas" ; }

        cout << endl ;

    }

}

/*  En recaudacionPaisDia, el objetivo es mostrar por país, por eso el bucle externo es sobre filas (países).
    En diasSinRecaudacion, el objetivo es analizar por día, por eso el bucle externo es sobre columnas (días). */

