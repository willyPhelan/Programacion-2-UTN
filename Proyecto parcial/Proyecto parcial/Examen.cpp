#include <iostream>
using namespace std;

#include "Examen.h"
#include "trabajo.h"
#include "ArchivoTrabajos.h"

const int CANTIDAD_PAISES_TOTAL = 40 ;

void Examen::Punto1(){

    const int ANIO_MINIMO_RECIENTE = 2023 ;

    ArchivoTrabajos arch("trabajos.dat") ;

    int cantidadRegistros = arch.CantidadRegistros() ;

    if (cantidadRegistros == 0) {

        cout << "PUNTO 1: El archivo 'trabajos.dat' esta vacio." << endl ;

        cout << "La cantidad de paises sin trabajos recientes (desde " << ANIO_MINIMO_RECIENTE << ") es: " << CANTIDAD_PAISES_TOTAL << endl ;

        return ;
    }


    Trabajo *vecTrabajos = new Trabajo[cantidadRegistros] ;

    if (vecTrabajos == nullptr) {

        cout << "Error: No se pudo asignar memoria dinamicamente." << endl ;

        return ;
    }


    arch.Leer(cantidadRegistros, vecTrabajos) ;

    bool paisesConTrabajoReciente[CANTIDAD_PAISES_TOTAL] = {false} ;

    int paisesRecientesCount = 0 ;

    for (int i = 0; i < cantidadRegistros; i++) {

        Trabajo t = vecTrabajos[i] ;

        int IDPais = t.getIDPais() ;

        int anioTrabajo = t.getFecha().getAnio() ;

        if (anioTrabajo >= ANIO_MINIMO_RECIENTE && IDPais >= 1 && IDPais <= CANTIDAD_PAISES_TOTAL) {

             int indice = IDPais - 1 ;

            if (!paisesConTrabajoReciente[indice]) {

                paisesConTrabajoReciente[indice] = true ;

                paisesRecientesCount++ ;
            }
        }
    }

    delete[] vecTrabajos ;

    int paisesSinTrabajoReciente = CANTIDAD_PAISES_TOTAL - paisesRecientesCount ;

    cout << "--------------------------------------------------------------------------------" << endl ;

    cout << "PUNTO 1: Informar la cantidad de paises que no tienen trabajos en los ultimos 3 anios." << endl ;

    cout << "(Considerando 'ultimos 3 anios' como trabajos a partir del anio " << ANIO_MINIMO_RECIENTE << ")" << endl ;

    cout << "Cantidad de paises sin trabajos recientes: " << paisesSinTrabajoReciente << endl ;

    cout << "--------------------------------------------------------------------------------" << endl ;


}

void Examen::Punto2(){


    const int UMBRAL_INTEGRANTES = 10 ;

    ArchivoTrabajos arch("trabajos.dat") ;

    int cantidadRegistros = arch.CantidadRegistros() ;

    if (cantidadRegistros == 0) {

        cout << "--------------------------------------------------------------------------------" << endl ;

        cout << "PUNTO 2: No hay registros de trabajos para analizar." << endl ;

        cout << "--------------------------------------------------------------------------------" << endl ;

        return ;
    }

    Trabajo *vecTrabajos = new Trabajo[cantidadRegistros] ;

    if (vecTrabajos == nullptr) {

        cout << "Error: No se pudo asignar memoria dinamicamente." << endl ;

        return ;
    }

    arch.Leer(cantidadRegistros, vecTrabajos) ;

    int idLiderMayorImporte = -1 ;

    float mayorImporteTrabajo = -1.0f ;

    for (int i = 0; i < cantidadRegistros; i++) {

        Trabajo t = vecTrabajos[i] ;

        if (t.getIDTrabajo() > 0 && t.getCantidadIntegrantes() > UMBRAL_INTEGRANTES) {

            float importeActual = t.getImporteTrabajo() ;

            int idLiderActual = t.getIDLiderEquipo() ;

            if (importeActual > mayorImporteTrabajo) {

                mayorImporteTrabajo = importeActual ;

                idLiderMayorImporte = idLiderActual ;
            }
        }
    }


     delete[] vecTrabajos ;

        cout << "--------------------------------------------------------------------------------" << endl ;

        cout << "PUNTO 2: Lider de equipo con mayor importe de trabajo en 1 proyecto individual (con mas de " << UMBRAL_INTEGRANTES << " integrantes)." << endl ;

    if (idLiderMayorImporte != -1) {

        cout << "ID Lider de Equipo: " << idLiderMayorImporte << endl ;

    } else {

        cout << "No se encontraron trabajos validos con mas de " << UMBRAL_INTEGRANTES << " integrantes." << endl ;

    }

    cout << "--------------------------------------------------------------------------------" << endl ;



}

void Examen::Punto3(){

    const int ANIO_MINIMO_TRASLADOS = 2022 ;

    ArchivoTrabajos arch("trabajos.dat") ;

    int cantidadRegistros = arch.CantidadRegistros() ;

    if (cantidadRegistros == 0) {

        cout << "--------------------------------------------------------------------------------" << endl ;

        cout << "PUNTO 3: No hay registros de trabajos para analizar." << endl ;

        cout << "--------------------------------------------------------------------------------" << endl ;

        return ;
    }

    Trabajo *vecTrabajos = new Trabajo[cantidadRegistros] ;

    if (vecTrabajos == nullptr) {

        cout << "Error: No se pudo asignar memoria dinamicamente." << endl ;

        return ;
    }

     arch.Leer(cantidadRegistros, vecTrabajos) ;

     float sumasImportesTraslados[CANTIDAD_PAISES_TOTAL] = {0.0f} ;

     for (int i = 0 ; i < cantidadRegistros; i++) {

        Trabajo t = vecTrabajos[i] ;

        int IDTrabajo = t.getIDTrabajo() ;

        int IDPais = t.getIDPais() ;

        int anioTrabajo = t.getFecha().getAnio() ;

        if (IDTrabajo <= 0 || IDPais < 1 || IDPais > CANTIDAD_PAISES_TOTAL) {

            continue ;
        }

        if (anioTrabajo >= ANIO_MINIMO_TRASLADOS) {

            float importeTraslado = t.getImporteTraslados() ;

            int indice = IDPais - 1 ;

            sumasImportesTraslados[indice] += importeTraslado ;
        }
    }

    delete[] vecTrabajos ;

    int idPaisMayorTraslado = -1 ;

    float mayorImporteAcumulado = -1.0f ;

    for (int i = 0; i < CANTIDAD_PAISES_TOTAL; i++) {

        float importeActual = sumasImportesTraslados[i] ;

        if (importeActual > mayorImporteAcumulado) {

            mayorImporteAcumulado = importeActual ;

            idPaisMayorTraslado = i + 1 ;
        }
    }

    cout << "--------------------------------------------------------------------------------" << endl ;

    cout << "PUNTO 3: Pais con mayor importe acumulado de traslados (desde el anio " << ANIO_MINIMO_TRASLADOS << ")." << endl ;

    if (idPaisMayorTraslado != -1) {

        cout << "ID Pais con Mayor Traslado Acumulado: " << idPaisMayorTraslado << endl ;

    } else {

        cout << "No se encontraron trabajos validos desde el anio " << ANIO_MINIMO_TRASLADOS << " con importes de traslado positivos." << endl ;
    }

    cout << "--------------------------------------------------------------------------------" << endl;




}
