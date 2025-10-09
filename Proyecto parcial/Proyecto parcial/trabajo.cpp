#include "Trabajo.h"

Trabajo::Trabajo(){
    _IDTrabajo = 0;
    _IDPais = 0;
    _IDLiderEquipo = 0;
    _cantidadIntegrantes = 0;
    _calificacion = 0;
    _importeTraslados = 0;
    _importeTrabajo = 0;
    _fecha = Fecha();
}

Trabajo::Trabajo(int ID, int IDPais, int IDLider, int integrantes, float calificacion, float traslado, float importe, Fecha fecha){
    _IDTrabajo = ID;
    _IDPais = IDPais;
    _IDLiderEquipo = IDLider;
    _cantidadIntegrantes = integrantes;
    _calificacion = calificacion;
    _importeTraslados = traslado;
    _importeTrabajo = importe;
    _fecha = fecha;
}

int Trabajo::getIDTrabajo(){
    return _IDTrabajo;
}

int Trabajo::getIDPais(){
    return _IDPais;
}

int Trabajo::getIDLiderEquipo(){
    return _IDLiderEquipo;
}

int Trabajo::getCantidadIntegrantes(){
    return _cantidadIntegrantes;
}

float Trabajo::getCalificacion(){
    return _calificacion;
}

float Trabajo::getImporteTraslados(){
    return _importeTraslados;
}

float Trabajo::getImporteTrabajo(){
    return _importeTrabajo;
}

Fecha Trabajo::getFecha(){
    return _fecha;
}

void Trabajo::setIDTrabajo(int ID){
    _IDTrabajo = ID;
}

void Trabajo::setIDPais(int IDPais){
    _IDPais = IDPais;
}

void Trabajo::setIDLiderEquipo(int IDLider){
    _IDLiderEquipo = IDLider;
}

void Trabajo::setCantidadIntegrantes(int cantidadIntegrantes){
    _cantidadIntegrantes = cantidadIntegrantes;
}

void Trabajo::setCalificacion(float calificacion){
    _calificacion = calificacion;
}

void Trabajo::setImporteTraslados(float importeTraslados){
    _importeTraslados = importeTraslados;
}

void Trabajo::setImporteTrabajo(float importe){
    _importeTrabajo = importe;
}

void Trabajo::setFecha(Fecha fecha){
    _fecha = fecha;
}

std::string Trabajo::toCSV(){

    std::string str = std::to_string(_IDTrabajo) + "," + std::to_string(_IDPais) + "," + std::to_string(_IDLiderEquipo) + "," + std::to_string(_cantidadIntegrantes) + "," + std::to_string(_calificacion) + "," + std::to_string((int) _importeTraslados) + "," + std::to_string((int) _importeTrabajo) + "," + _fecha.toString();
    return str;
}
