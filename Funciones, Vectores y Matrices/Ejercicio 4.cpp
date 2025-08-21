/*4- Realizar una función que reciba una matriz de dimensiones 30×12 con valores numéricos.
La función debe mostrar, para cada fila, la suma de todos los valores de sus columnas.
Se debe especificar claramente en la salida qué fila se está mostrando y cuál es su suma.*/

#include <iostream>

using namespace std ;

void reciboMatriz(int mat[30][12], int filas, int columnas); // void porque la fn no devuelve nada para ser usado luego en otro lado

int main() {

    const int FILAS = 30, COLUMNAS = 12 ; // defino el tamanio de las filas y columnas de la matriz

    int mat[FILAS][COLUMNAS];

    // Lleno la matriz con datos de ejemplo random

    for (int i = 0; i < FILAS; i++) {

        for (int j = 0; j < COLUMNAS; j++) {

            mat[i][j] = i + j; // ejemplo simple con esto se va llenando la matriz
        }
    }

    reciboMatriz(mat, FILAS, COLUMNAS) ; // llamo a la funcion

}

 void reciboMatriz(int mat[30][12], int filas, int columnas) {

    int i, j ;

    for(i = 0 ; i < filas ; i++){ // mat[i] NO es un numero, sino que representa a la fila completa. // for para recorrer las filas

    int cantPorFila=0 ; // inicializo la variable aca porque este es el for que recorre las filas, de modo que cuando termine de recorrer la fila devolvera la suma y se reinicia esta variable paera poder calcular la suma de las proximas filas.

    for(j = 0 ; j < columnas ; j++){ // for para recorrer las columnas

        cantPorFila += mat[i][j] ; // aca voy acumulando los valores por cada fila

         }

         cout << "Fila " << i << ": suma = " << cantPorFila << endl ;

          }

    }
