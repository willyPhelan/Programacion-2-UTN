#pragma once
#include "Fecha.h"

class Trabajo{
    private:
        int _IDTrabajo, _IDPais, _IDLiderEquipo, _cantidadIntegrantes;
        float _calificacion, _importeTraslados, _importeTrabajo;
        Fecha _fecha;

    public:
    Trabajo();
    Trabajo(int, int, int, int, float, float, float, Fecha);

    int getIDTrabajo();
    int getIDPais();
    int getIDLiderEquipo();
    int getCantidadIntegrantes();
    float getCalificacion();
    float getImporteTraslados();
    float getImporteTrabajo();
    Fecha getFecha();

    void setIDTrabajo(int );
    void setIDPais(int);
    void setIDLiderEquipo(int);
    void setCantidadIntegrantes(int );
    void setCalificacion(float);
    void setImporteTraslados(float);
    void setImporteTrabajo(float);
    void setFecha(Fecha);

    std::string toCSV();

};
