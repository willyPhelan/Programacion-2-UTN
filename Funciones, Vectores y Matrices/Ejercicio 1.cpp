/*
1- Realizar una función llamada pedirNumeroPositivo.
La función debe solicitar al usuario un número, asegurarse de que dicho número sea estrictamente positivo (mayor que cero) y devolverlo.
En caso de que el usuario ingrese un valor inválido, la función debe volver a solicitarlo hasta que sea correcto.
*/

#include <iostream>

using namespace std ;

int pedirNumeroPositivo() ; // La fn no recibe parámetros porque se encarga de pedir el número al usuario

int main() {

    int num ;

    num = pedirNumeroPositivo() ; // en main llamo a la funcion que declare y guardo el valor que devuelve en una variable (num)

    return 0 ;

}

int pedirNumeroPositivo(){ // fuera de main desarrollo la fn.

    int num ;

    cout << "Ingrese un numero: " << endl ;
    cin >> num ;
    cout << endl ;

    while(num <= 0) {

    cout << "El numero " << num << " no es positivo, ingrese otro numero: " << endl ;
    cin >> num ;
    cout << endl ;

    }

    if (num > 0){

        cout << "El numero " << num << " es positivo" << endl ;

    }

    return num ; // debe retornar el numero pedido asi pouedo capturarlo desde main

}
