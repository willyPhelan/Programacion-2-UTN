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

   cout << "--- PUNTO 1: Servicios de Mesa con Propina ---" << endl ;

   // Se utiliza el archivo de datos "restaurant.dat"

   ArchivoServicioMesa archivo("restaurant.dat") ;

   ServicioMesa registro ;

   int i ;

   int cantidadRegistros = archivo.CantidadRegistros() ;

    // Encabezado

   cout << "ID Servicio | Recibe propina? " << endl ;
   cout << "-------------------------------" << endl ;

   // Recorre todos los registros del archivo

   for(i = 0; i < cantidadRegistros; i++){

      registro = archivo.Leer(i) ;

      int idServicio = registro.getIDServicioMesa() ;

      float propina = registro.getPropina() ;

      string tienePropina = "NO" ;

      // Condición: Se considera propina si el valor es mayor a 0

      if(propina > 0){ tienePropina = "SI" ; }

      // Muestra el ID del Servicio y el resultado de la verificación de propina

      cout << idServicio << " | " << tienePropina << endl;
   }

   cout << "-----------------------------------------------" << endl;
}



void Examen::Punto2(){

    cout << endl <<"PUNTO 2.1: Servicios con Puntaje Superior al Promedio:" << endl << endl;

   ArchivoServicioMesa archivo("restaurant.dat") ;

   ServicioMesa registro ;

   int cantidadRegistros = archivo.CantidadRegistros() ;

   // Si no hay registros, no se puede calcular el promedio

   if (cantidadRegistros == 0) {

       cout << "El archivo no contiene registros de servicios de mesa." << endl ;

       cout << "-----------------------------------------------" << endl ;

       return ;
   }

   // --- PASO 1: Calcular el Puntaje Promedio ---

   float sumaTotalPuntajes = 0 ;


   /////////////////////////////////

  // variables para consigna 2 (Recaudación por Plato)

   // Los platos van del 1 al 70. Usamos el tamaño estricto de 70 y un offset (ID - 1)

   const int MAX_PLATOS = 70 ; // Dimension estrictamente necesaria para IDs 1 a 70

   float recaudacionPorPlato[MAX_PLATOS] ; // Declaración de array con constante

   for (int i = 0; i < MAX_PLATOS; i++) {

       recaudacionPorPlato[i] = 0 ;
   }

   ////////////////////////////////

    // Variables para la consigna 2.3 (Propina por Mozo - Array de tamaño 20)

   const int MAX_MOZOS = 20 ;

   float propinaPorMozo[MAX_MOZOS] ;

    for (int i = 0; i < MAX_MOZOS; i++) {

       propinaPorMozo[i] = 0;
   }

   ///////////////////////////////

   // Se recomienda cargar todos los registros en memoria para un segundo pase (si la cantidad no es excesiva)
   // En este caso, lo haremos cargando y recorriendo el archivo dos veces, usando los metodos de ArchivoServicioMesa

   for(int i = 0 ; i < cantidadRegistros ; i++){

      registro = archivo.Leer(i) ;

      sumaTotalPuntajes += registro.getPuntajeObtenido() ; // El puntaje es de tipo float


    // Consigna 2: Acumulación de Importe por Plato

      int idPlato = registro.getIDPlato();

      // Verificación de límite e inserción con desplazamiento (ID - 1)

      if (idPlato >= 1 && idPlato <= MAX_PLATOS) { // MAX_PLATOS ahora es 70

           // IDPlato 1 -> índice 0, IDPlato 70 -> índice 69

           recaudacionPorPlato[idPlato - 1] += registro.getImporte() ;
      }


    // Consigna 2.3: Acumulación de Propina por Mozo (Filtrado por año 2024 y propina > 0)

      Fecha fechaServicio = registro.getFecha() ;

      float propina = registro.getPropina() ;

      int idMozo = registro.getIDMozo() ;

      if (fechaServicio.getAnio() == 2024 && propina > 0) {

          // Mapeo ID 1-20 a índice 0-19

          if (idMozo >= 1 && idMozo <= MAX_MOZOS) {

               propinaPorMozo[idMozo - 1] += propina ;
          }



      }
   }



   float puntajePromedio = sumaTotalPuntajes / cantidadRegistros ;

   cout << "Puntaje Promedio General: " << puntajePromedio << endl ;

   // --- PASO 2: Contar registros con Puntaje Mayor al Promedio ---

   int serviciosConPuntajeSuperior = 0 ;

   for(int i = 0 ; i < cantidadRegistros ; i++){

      registro = archivo.Leer(i) ;

      if(registro.getPuntajeObtenido() > puntajePromedio){

         serviciosConPuntajeSuperior++ ;
      }
   }

   cout << "Cantidad de servicios valorados por encima del promedio: " << serviciosConPuntajeSuperior << endl ;
   cout << endl << "-----------------------------------------------" << endl ;


   // --- 2.2) Número de plato que recaudó mayor cantidad de dinero

   int idPlatoMasRecaudador = -1 ;
   float maxRecaudacion = 0 ;

   // Buscar el plato con la máxima recaudación en el array de 70 posiciones (índices 0 a 69)

   for (int i = 0; i < MAX_PLATOS ; i++) {

       if (recaudacionPorPlato[i] > maxRecaudacion) {

           maxRecaudacion = recaudacionPorPlato[i] ;

           // El ID del plato es el índice + 1

           idPlatoMasRecaudador = i + 1 ;
       }
   }

   if (idPlatoMasRecaudador != 0) {

        cout << endl <<"PUNTO 2.2: Servicios con Puntaje Superior al Promedio" << endl << endl;

        cout << "El numero de plato que recaudo mayor cantidad de dinero es el ID: " << idPlatoMasRecaudador << endl ;

   } else {

        cout << "\n2) No se encontro un plato con recaudacion." << endl ;
   }

   cout << endl << "-----------------------------------------------" << endl ;




    // --- 2.3) Mozo que recibió mayor cantidad total de propinas en el año 2024

   int idMozoMasPropinas = 0 ;

   float maxPropina = -1 ;

   // Buscar el mozo con la máxima propina

   for (int i = 0; i < MAX_MOZOS; i++) {

       if (propinaPorMozo[i] > maxPropina) {

           maxPropina = propinaPorMozo[i] ;

           idMozoMasPropinas = i + 1 ; // El ID del mozo es el índice + 1
       }
   }

   cout << endl << "PUNTO 2.3: Mozo con Mayor Propina en 2024" << endl << endl ;

   if (idMozoMasPropinas != 0) {

        cout << "El numero de mozo que recibio mayor cantidad total de propinas en 2024 es el ID: " << idMozoMasPropinas ;


   } else {

        cout << "Ningún mozo recibió propinas en el año 2024." << endl ;
   }

   cout << endl << "-----------------------------------------------" << endl ;
}



void Examen::Punto3(){

}
