/*
2- Realizar una función llamada pedirNumeroEntre que reciba dos parámetros: inicio y fin.
La función debe solicitar un número entero al usuario y asegurarse de que se encuentre dentro del rango [inicio, fin].
El parámetro fin debe ser opcional: si no se especifica, el rango debe considerarse desde inicio hasta el valor máximo que pueda tomar una variable entera (INT_MAX).
En caso de ingreso inválido, la función debe volver a solicitar el número.

3- Extender la funcionalidad de pedirNumeroEntre para que también pueda aceptar números decimales (tipo float), manteniendo la validación de rango.
El comportamiento respecto al parámetro opcional fin debe mantenerse igual.


*/

#include <iostream>
#include <climits> // para usar INT_MAX y numeric_limits -> permiten definir valores maximos al que puede llegar un entero o un decimal

using namespace std ;

int pedirNumeroEntre(float inicio, float fin=INT_MAX) ; // funcion de tipo int porque devuelve un numero, INT_MAX es definido como parametro por defecto

int main() {

   float num, inicio, fin ; // admite enteros y decimales porque float puede almacenar ambos.

    cout << "Ingrese un numero para determinar el inicio:" << endl ; // determino inicio y fin.
    cin >> inicio ;

    cout << "Ingrese el fin del rango (opcional): ";
    cin >> fin ;

     if (!fin) {

        num = pedirNumeroEntre(inicio) ; // guardo el valor que devuelve la fn en la variable num

    } else {

        num = pedirNumeroEntre(inicio, fin) ;

    }

    return 0 ; // Todo salió bien

    }

int pedirNumeroEntre(float inicio, float fin){

int num ;

 cout << "Ingrese un numero" << endl ;
 cin >> num ;

while(true){

   if(num >= inicio && num <= fin){

       cout << "El numero esta dentro de los parametros de inicio y fin" << endl ;

        break ;

} else {

        cout << "Numero invalido. Ingrese otro: " << endl ;
        cin >> num ;

        }



}
return num ;
}
