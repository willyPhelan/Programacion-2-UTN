#pragma once
#include <string>
#include "trabajo.h"

class ArchivoTrabajos{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoTrabajos(std::string nombreArchivo);
        bool Guardar(Trabajo );
        bool Guardar(Trabajo, int);
        int Buscar(int );
        Trabajo Leer(int );
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Trabajo *vector);
};
