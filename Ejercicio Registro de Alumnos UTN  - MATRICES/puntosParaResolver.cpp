#include "funciones.h"
#include <iostream>
#include <string>

using namespace std;

void cargarMaterias(string nombreDeMateria[], int alumnosProfesores[][2], int cantidadMaterias) {

    int nroMateria ;

    for(int i = 0; i < cantidadMaterias; i++) {

        do {
            cout << endl << "Ingrese el numero de materia (1-" << cantidadMaterias << "): " ;
            cin >> nroMateria ;

            } while(nroMateria < 1 || nroMateria > cantidadMaterias) ;

                cout << "Ingrese el nombre de la materia: " ;
                cin >> nombreDeMateria[nroMateria-1] ; // lo agrego en la posicion 0 del array

                cout << "Ingrese cantidad de alumnos: " ;
                cin >> alumnosProfesores[nroMateria-1][0] ; // lo agrego en la fila 0 columna 0 de la matriz (alumnos)

                cout << "Ingrese cantidad de profesores: " ;
                cin >> alumnosProfesores[nroMateria-1][1] ; // lo agrego en la fila 0 columna 1 de la matriz (profesores)
    }
}


void registrarAccesos(int accesosTotales[], float horasTotales[], int cantidadIngresos[][31], int cantidadMaterias) {

    int legajo, dia, mes, nroMateria ;

    float cantidadHoras ;

    cout << "Ingrese legajo (0 para finalizar): ";
    cin >> legajo ;

    while(legajo != 0) {

        do {

            cout << "Ingrese dia de ingreso (1-31): " ;
            cin >> dia ;

        } while(dia < 1 || dia > 31) ;

        do {

            cout << "Ingrese mes de ingreso (1-12): ";
            cin >> mes ;

        } while(mes < 1 || mes > 12) ;

        do {
            cout << "Ingrese numero de materia (1-" << cantidadMaterias << "): " ;
            cin >> nroMateria ;

        } while(nroMateria < 1 || nroMateria > cantidadMaterias) ;

        cout << "Ingrese cantidad de horas: " ;
        cin >> cantidadHoras ;

        // Acumulo los datos

        accesosTotales[nroMateria-1]++ ; // por materia accedida voy aumentando el contador

        horasTotales[nroMateria-1] += cantidadHoras ;// le voy sumando a cada materia el numero de horas en las que hubo acceso

        if(mes == 3) {

            cantidadIngresos[nroMateria-1][dia-1]++ ; // llevo la cuenta de los dias en los que hubo acceso en el mes de Marzo
        }

        cout << "Ingrese legajo (0 para finalizar): " ;
        cin >> legajo ;
    }
}

void mostrarMateriasSinAcceso(string nombreDeMateria[], int accesosTotales[], int cantidadMaterias) {

    int contadorSinAcceso = 0 ;

    cout << "\n Materias que no tuvieron ningun acceso:\n" ;

    for(int i = 0; i < cantidadMaterias; i++) {

        if(accesosTotales[i] == 0) {

            cout << "- " << nombreDeMateria[i] << endl ;

            contadorSinAcceso++;
        }
    }

    if(contadorSinAcceso == 0)

        cout << "Todas las materias tuvieron al menos un acceso.\n" ;
}

void mostrarMateriaMasHoras(float horasTotales[], string nombreDeMateria[], int cantidadMaterias) {

    int indiceMax = 0 ;

    float maxHoras = horasTotales[0] ;

    for(int i = 1; i < cantidadMaterias; i++) {

        if(horasTotales[i] > maxHoras) {

            maxHoras = horasTotales[i] ;

            indiceMax = i ; // guardo la posicion del indice cuando este posicionado en la materia con mas horas de acceso
        }
    }

    cout << "\n La materia con mayor cantidad de horas de acceso es: "

         << nombreDeMateria[indiceMax] << " con " << maxHoras << " horas.\n";
}

void mostrarCantidadIngresosDeMarzo(string nombreDeMateria[], int cantidadIngresos[][31]) {

    for(int i = 0; i < 20; i++) {

        cout << "Materia: " << nombreDeMateria[i] << endl ;

        for(int j = 0; j < 31; j++) {

            cout << "Dia #" << j+1 << ": " << cantidadIngresos[i][j] << endl ;
        }
    }
}
