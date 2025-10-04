#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}


 void Examen::Punto1(){

    cout << endl << "PUNTO 1: Servicios con Puntaje Superior al Promedio: " << endl << endl ;

    ArchivoServicioMesa archivo("restaurant.dat") ;

    ServicioMesa registro ;

    int cantidadRegistros = archivo.CantidadRegistros() ;

    float puntajePromedio ;

    if (cantidadRegistros == 0) {

        cout << "El archivo no contiene registros de servicios de mesa." << endl ;

        cout << "-----------------------------------------------" << endl ;

        return ;
    }

    // --- PASO 1: Calcular el Puntaje Promedio (Primer Pase) ---

    float sumaTotalPuntajes = 0 ;

    for(int i = 0 ; i < cantidadRegistros ; i++){

        registro = archivo.Leer(i) ;

        sumaTotalPuntajes += registro.getPuntajeObtenido() ;
    }

    if( cantidadRegistros > 0 ){


    puntajePromedio = sumaTotalPuntajes / cantidadRegistros ; } ;



    // --- PASO 2: Contar registros con Puntaje Mayor al Promedio (Segundo Pase) ---

    int serviciosConPuntajeSuperior = 0 ;

    for(int i = 0 ; i < cantidadRegistros ; i++){

        registro = archivo.Leer(i) ;

        if(registro.getPuntajeObtenido() > puntajePromedio){

            serviciosConPuntajeSuperior++ ;
        }
    }

    cout << "Cantidad de servicios valorados por encima del promedio: " << serviciosConPuntajeSuperior << endl ;

    cout << endl << "----------------------------------------------------------------------------" << endl ;

}



void Examen::Punto2(){


cout << endl << "PUNTO 2: Plato con Mayor Recaudacion" << endl << endl ;

    ArchivoServicioMesa archivo("restaurant.dat") ;

    ServicioMesa registro ;

    int cantidadRegistros = archivo.CantidadRegistros() ;


    if (cantidadRegistros == 0) {

        cout << "El archivo no contiene registros de servicios de mesa." << endl ;

        cout << endl << endl << "----------------------------------------------------------------------------" << endl ;

        return ;
    }

    // --- PASO 1: Acumular Recaudación por Plato (Pase Único) ---

    const int MAX_PLATOS = 70 ;

    float recaudacionPorPlato[MAX_PLATOS] ;

    for (int i = 0; i < MAX_PLATOS; i++) {

        recaudacionPorPlato[i] = 0 ;

    }

    for(int i = 0 ; i < cantidadRegistros ; i++){

        registro = archivo.Leer(i) ;

        int idPlato = registro.getIDPlato();

        if (idPlato >= 1 && idPlato <= MAX_PLATOS) {

            // Mapeo ID -> índice (ID - 1)

            recaudacionPorPlato[idPlato - 1] += registro.getImporte() ;
        }
    }

    // --- PASO 2: Buscar el plato con la máxima recaudación ---

    int idPlatoMasRecaudador = 0 ;

    float maxRecaudacion = -1 ;

    for (int i = 0; i < MAX_PLATOS ; i++) {

        if (recaudacionPorPlato[i] > maxRecaudacion) {

            maxRecaudacion = recaudacionPorPlato[i] ;

            idPlatoMasRecaudador = i + 1 ; // ID del plato = índice + 1
        }
    }

    if (idPlatoMasRecaudador != 0) {

        cout << "El numero de plato que recaudo mayor cantidad de dinero es el ID: " << idPlatoMasRecaudador ;

    } else {

        cout << "No se encontro un plato con recaudacion." << endl ;
    }

    cout << endl << endl << "----------------------------------------------------------------------------" << endl ;
}




void Examen::Punto3(){

    cout << endl << "PUNTO 3: Mozo con Mayor Propina en 2024" << endl << endl ;

    ArchivoServicioMesa archivo("restaurant.dat") ;

    ServicioMesa registro ;

    int cantidadRegistros = archivo.CantidadRegistros() ;

    if (cantidadRegistros == 0) {

        cout << "El archivo no contiene registros de servicios de mesa." << endl ;

        cout << "-----------------------------------------------" << endl ;

        return ;
    }

    // --- PASO 1: Acumulación de Propina por Mozo (Pase Único) ---

    const int MAX_MOZOS = 20 ;

    int contadorServiciosConPropina[MAX_MOZOS] ;

    for (int i = 0; i < MAX_MOZOS; i++) {

        contadorServiciosConPropina[i] = 0;
    }

    for(int i = 0 ; i < cantidadRegistros ; i++){

        registro = archivo.Leer(i) ;

        Fecha fechaServicio = registro.getFecha() ;

        float propina = registro.getPropina() ;

        int idMozo = registro.getIDMozo() ;

        // Filtro: Año 2024 y Propina > 0

        if (fechaServicio.getAnio() == 2024 && propina > 0) {

            if (idMozo >= 1 && idMozo <= MAX_MOZOS) {

                 // Mapeo ID -> índice (ID - 1)

                 contadorServiciosConPropina[idMozo - 1] += 1 ;
            }
        }
    }

    // --- PASO 2: Buscar el mozo con la máxima propina ---

    int idMozoMasServiciosConPropina = 0 ;
    int maxConteo = -1 ; // Debe ser -1 para permitir que un conteo de 0 sea superado.

    for (int i = 0; i < MAX_MOZOS; i++) {

        if (contadorServiciosConPropina[i] > maxConteo) {

            maxConteo = contadorServiciosConPropina[i] ;

            idMozoMasServiciosConPropina = i + 1 ; // ID del mozo = índice + 1
        }
    }

    if (idMozoMasServiciosConPropina != 0) {

        cout << "El numero de mozo que recibio propina en la MAYOR CANTIDAD DE SERVICIOS en 2024 es el ID: " << idMozoMasServiciosConPropina ;

    } else {

        cout << "Ningun mozo recibio propinas en el año 2024." << endl ;
    }

    cout << endl << endl << "----------------------------------------------------------------------------" << endl ;




}
