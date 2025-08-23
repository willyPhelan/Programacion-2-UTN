/*
LAS AUTORIDADES DE LA CARRERA TUP DE LA UTN ESTÁN REALIZANDO UN ANÁLISIS DE LOS CURSOS VIRTUALES DE LAS DISTINTAS MATERIAS.
POR CADA UNA DE LAS 20 MATERIAS DE LA CARRERA TIENE LA SIGUIENTE INFORMACIÓN: -> como sabemos que son 20 materias, para cargarlas solo tenemos que utilizar un FOR // NO se puede saber si los datos vendran ordenados!

• NÚMERO DE MATERIA (ENTRE 1 Y 20), NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES.

 ADEMÁS POR CADA INGRESO DE LOS ESTUDIANTES AL AULA VIRTUAL SE REGISTRA LO SIGUIENTE:

• LEGAJO, FECHA DE ACCESO (DÍA Y MES), NÚMERO DE LA MATERIA A LA QUE INGRESO, CANTIDAD DE HORAS (NÚMERO REAL).
  EL FIN DE LOS DATOS SE INDICA CON UN NÚMERO DE LEGAJO IGUAL A 0.

  SE QUIERE RESPONDER LAS SIGUIENTES PREGUNTAS:
  a) LAS MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS NUNCA
  b) LA MATERIA QUE MÁS CANTIDAD DE HORAS REGISTRO DE ACCESO DE ALUMNOS
  c) POR CADA MATERIA Y DÍA DE MARZO, LA CANTIDAD DE ACCESOS DE ALUMNOS A LAS AULAS VIRTUALES.

• HACER UN PROGRAMA EN EL MARCO DE UN PROYECTO DE CODEBLOCK CON UN MENÚ CON OPCIONES PARA CARGAR LOS DATOS, MOSTRAR CADA PUNTO Y SALIR DEL PROGRAMA */

#include <iostream>
#include <string>
#include "funciones.h"

using namespace std;

const int CANT_MATERIAS = 20 ; // constante para definir la cantidad de materias, lo puedo cambiar facilmente
const int DIAS_MARZO = 31 ; // constante para determinar los dias del mes

const int ALUMNOS = 0 ;
const int PROFESORES = 1 ;

int main() {

    int alumnosProfesores[CANT_MATERIAS][2] = {} ; // matriz con 20 filas y 2 columnas correspondientes a alumnos y profesores
    string nombreDeMateria[CANT_MATERIAS] ; // array con capacidad de almacenar los 20 nombres de cada materia
    int accesosTotales[CANT_MATERIAS] = {} ; // array incializado en 0 que servira como contados para los accesos que hubo en cada materia
    float horasTotales[CANT_MATERIAS] = {} ; // array contador inicializado en 0 que servira para llevar la cuanta de cual de las 20 fue la materia con mas horas estudiadas
    int cantidadIngresos[CANT_MATERIAS][DIAS_MARZO] = {} ; // array contador para llevar la cuenta de la cantidad de accesos en marzo

   // Para el menu:

    int opcion ;
    bool materiasCargadas = false ;
    bool accesosCargados = false ;

    do {
        cout << "\n--- MENU ---\n" ;
        cout << "1. Cargar materias\n" ;
        cout << "2. Registrar accesos de alumnos\n" ;
        cout << "3. Mostrar materias sin accesos (punto A)\n" ;
        cout << "4. Mostrar materia con mayor cantidad de horas (punto B)\n" ;
        cout << "5. Mostrar accesos de alumnos por dia de marzo (punto C)\n" ;
        cout << "6. Salir\n" ;
        cout << endl << "Ingrese opcion: " ;
        cin >> opcion ;

        switch(opcion) {

            case 1:

                cargarMaterias(nombreDeMateria, alumnosProfesores, CANT_MATERIAS) ; // fn que recibe el array con nombres de materias, la matriz con las materias y cantidad de alumnos y profesores y la cant de materias

                materiasCargadas = true ;

                break ;

            case 2:

                if(!materiasCargadas) {

                    cout << endl << "Primero debe cargar las materias.\n" ;

                } else {

                    registrarAccesos(accesosTotales, horasTotales, cantidadIngresos, CANT_MATERIAS) ; // recibe array con el contador de accesos totales, el array contador de horas totales, el array contador de la cantidad de ingreoss para MARZO y las 20 materias definidas en una constante

                    accesosCargados = true ;
                }

                break ;

            case 3:

                if(!accesosCargados) {

                    cout << endl << "Primero debe registrar los accesos.\n" ;

                } else {

                    mostrarMateriasSinAcceso(nombreDeMateria, accesosTotales, CANT_MATERIAS) ;
                }

                break ;

            case 4:

                if(!accesosCargados) {

                    cout << endl  << "Primero debe registrar los accesos.\n" ;

                } else {

                    mostrarMateriaMasHoras(horasTotales, nombreDeMateria, CANT_MATERIAS);
                }

                break;

            case 5:

                if(!accesosCargados) {

                    cout << "Primero debe registrar los accesos.\n" ;

                } else {

                    mostrarCantidadIngresosDeMarzo(nombreDeMateria, cantidadIngresos);
                }
                break ;

            case 6:

                cout << "Saliendo del programa.\n" ;

                break ;

            default:

                cout << "Opcion invalida.\n" ;
        }

    } while(opcion != 6);

    return 0;
}
