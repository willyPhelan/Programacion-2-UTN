#pragma once
#include <iostream>
#include "Fecha.h"
#include "Direccion.h"

using namespace std;

class Socio {

private:

    int dni, idSocio ;
    char nombre[30], apellido[30], telefo[15], email[40] ;
    Fecha fechaNacimiento ;
    Direccion domicilio ;

public:

    void cargar() ;
    void mostrar() ;

    int getIdSocio() ;
    Fecha getFechaNacimiento() ;
    Direccion getDomicilio() ;
    int getDNI() ;

    void setIdSocio(int id) ;
    void setFechaNacimiento(Fecha nac) ;
    void setDomicilio(Direccion dom) ;
    void setDiaNacimiento(int d) ;


} ;


