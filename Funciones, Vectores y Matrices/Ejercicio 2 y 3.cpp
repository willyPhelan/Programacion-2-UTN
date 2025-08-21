/*
2- Realizar una funci�n llamada pedirNumeroEntre que reciba dos par�metros: inicio y fin.
La funci�n debe solicitar un n�mero entero al usuario y asegurarse de que se encuentre dentro del rango [inicio, fin].
El par�metro fin debe ser opcional: si no se especifica, el rango debe considerarse desde inicio hasta el valor m�ximo que pueda tomar una variable entera (INT_MAX).
En caso de ingreso inv�lido, la funci�n debe volver a solicitar el n�mero.

3- Extender la funcionalidad de pedirNumeroEntre para que tambi�n pueda aceptar n�meros decimales (tipo float), manteniendo la validaci�n de rango.
El comportamiento respecto al par�metro opcional fin debe mantenerse igual.


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

    return 0 ; // Todo sali� bien

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
