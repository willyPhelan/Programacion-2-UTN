// ORDENAMIENTO BURGBUUJA Y SIDE EFFECT

#include <iostream>


using namespace std ;

 void ordenamientoBurbuja(int vec[], int cant){
    for (int i = 0 ; i < cant - 1 ; i++){
        for(int j = 0 ; j < cant -1 ; j++){
            if(vec[j] > vec[j+1]){
                int aux = vec[j] ;
                vec[j] = vec[j+1] ;
                vec[j+1] = aux ;
            }
        }
    }
}

void mostrar(const int vec[], int cant){

for(int i = 0 ; i < cant ; i++){

    cout << i + 1 << "=" << vec[i] << endl ;
} }


void mostrarOrdenado(const int vec[], int cant){

    int *vecAux ; // trabajo sobre una copia del vector para evitar efectos seundarios de funciones

    vecAux = new int[cant] ; // pido memoria

    if (vecAux == nullptr) {

        cout << "No hay memoria" << endl ;

        exit(101) ;
    }

    // ya pedi memoria para el vector auxiliar, ahora debo llear el vector auxiliar con el contenido del vector original

    for(int i = 0 ; i < cant ; i++) {
        vecAux[i] = vec[i] ;
    }

    ordenamientoBurbuja(vecAux, cant) ;
    mostrar(vecAux, cant) ;

    delete [] vecAux ; } // libero memoria


int main() {

    int vec[5] = {2, 6, 5, 4, 8} ;

    mostrar(vec, 5) ;

	cout << "---" << endl ;

	mostrarOrdenado(vec, 5) ;

	cout << endl << vec[1] << endl ; //     quiero mostrar el segundo elemento del array (indice 1)

	return 0 ;
 }
