 #pragma once
 #include <string>

using namespace std ;

void cargarMaterias(string nombreDeMateria[], int alumnosProfesores[][2], int cantidadMaterias) ;
void registrarAccesos(int accesosTotales[], float horasTotales[], int cantidadIngresos[][31], int cantidadMaterias) ;
void mostrarMateriasSinAcceso(string nombreDeMateria[], int accesosTotales[], int cantidadMaterias) ;
void mostrarMateriaMasHoras(float horasTotales[], string nombreDeMateria[], int cantidadMaterias) ;
void mostrarCantidadIngresosDeMarzo(string nombreDeMateria[], int cantidadIngresos[][31]) ;

