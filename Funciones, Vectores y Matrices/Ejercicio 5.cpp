/*
5- Registro de asistencias en una empresa
 Una empresa lleva un registro de asistencia de sus 30 empleados.
 Cada vez que un empleado asiste al trabajo, se registra:
●	Número de empleado (valor entre 100 y 129).
●	Mes (1 a 12).
●	Día (1 a 31).
●	Horas trabajadas en el día.
Los registros finalizan cuando se ingresa un número de empleado igual a 0.
Al finalizar la carga, se debe calcular y mostrar:
1.	El total de horas trabajadas en el mes de abril entre todos los empleados.
2.	Para cada mes del año, la cantidad de días en los que al menos un empleado estuvo presente.
3.	Para cada empleado, su número de empleado y la cantidad total de meses en los que trabajó.

*/

#include <iostream>

void cargarRegistro() ;

using namespace std ;

int main() {

    cout << "Registro de empleados y horas trabajadas" << endl ;

    cargarRegistro() ;

}

void cargarRegistro(){

int nroEmpleado, mes, dia, horas ;
int horasAbril=0 ;

int meses[31][12] = {0} ; // [día]filas [mes]columnas // tengo que usar una matriz porque necesito un arreglo de 31 elementos (los dias) por casa uno de los meses del anio // al principio la inicializo en 0

int empleados[30][12] = {0} ; // punto 3. Inicializo una matriz para marcar que meses trabajo cada empleado

    cout << endl ;

    cout << "Ingresar el numero de empleado (entre 100 y 129)" << endl ;
    cin >> nroEmpleado ;

while (nroEmpleado != 0) {

    cout << "Ingresar el mes (de 1 a 12)" << endl ;
    cin >> mes ;

    cout << "Ingresar el dia (de 1 a 31)" << endl ;
    cin >> dia ;

    cout << "Ingresar el numero de horas trabajadas" << endl ;
    cin >> horas ;

    cout << endl ;

     if(mes == 4){
        horasAbril += horas ;
    }

    meses[dia - 1][mes - 1] = 1; // PUNTO 2 - marco asistencia. por cada dia que se asiste al trabajo, lo marco en la matriz, al igual que en arrays, las matrices comienzan en 0 por lo que debo restar 1. si el mes es 3, la posicion correspondiente en la matriz sera 2, lo mismo con los meses.
                                    // debe estar siempre dentro del while para que tome asistencia por casa vuelta si lo pongo afuera solo contara la ultima


    // PUNTO 3 // defino el indice para empleados (como los empeados van del 100 al 129 al nro de empleado le resto 100 para que ocupe su lugar correspondiente en la matriz, si el empleado fuera el numero 100 le corresponderia la posicion 0 de la matriz y asi sucesivamente)

    if (nroEmpleado >= 100 && nroEmpleado <= 129) {

    int indiceEmpleado = nroEmpleado - 100 ;

    empleados[indiceEmpleado][mes - 1] = 1 ;  // al igual que en el punto 2 por cada mes que el empleado marque que trabajo

    } else { cout << "Numero de empleado invalido. Debe estar entre 100 y 129." << endl ; }


    // MUY IMPORTANTE marcar asitencia antes de pedir un nuevo numero de empleado porque si se ingresa un 0 (para finalizar) se accede a una posicion del array inexistente probocando problemas en la memoria y el programa

    cout << "Ingresar un nuevo numero de empleado entre 100 y 129 (0 para finalizar)" << endl ;
    cin >> nroEmpleado ;




}

    cout << endl ;

    cout << "Horas trabajadas en Abril: " << horasAbril << endl ;

    // RESOLUCION DEL PUNTO 2 //

    cout << "\n--- Resumen de dias trabajados por mes ---\n" ;

    for (int i = 0; i < 12; i++) { // for para recorrer las columnas de la matriz correspondientes a los meses del anio

        int cantDias = 0 ; // antes de recorrer las filas inicializo el contador

        for (int j = 0 ; j < 31; j++) { // for para recorrer los dias de cada mes (filas)

            if (meses[j][i] == 1) cantDias++ ; // si se marco asistencia ( meses[dia - 1][mes - 1] = 1) aumento el contador.
        }

        if (cantDias > 0) {

            cout << "Mes " << (i + 1) << ": " << cantDias << " dia/s trabajados." << endl;
        }
    }

    // RESOLUCION DEL PUNTO 3 // Para cada empleado, su número de empleado y la cantidad total de meses en los que trabajó.

    // para esto necesito una nueva matriz de empleados para poder ir macando los meses que cada empleado trabajo.


    cout << "\n--- Cantidad de meses trabajadas por cada empleado ---\n" ;

    for (int e = 0 ; e < 30 ; e++) { // recorro a cada empleado

    int mesesTrabajados = 0 ;

    for (int m = 0 ; m < 12 ; m++) { // recorro los meses

        if (empleados[e][m] == 1) { // recorro cada empleado y me fijo si marco asitencia en cada mes, por cada mes que asistio al trabajo aumento el valor del contador

            mesesTrabajados++ ;
        }
    }

    if (mesesTrabajados > 0) {

        cout << "Empleado " << (100 + e) << ": " << mesesTrabajados << " mes/es trabajados.\n";
    }
}



}
