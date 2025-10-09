#include "Fecha.h"
#include "ArchivoTrabajos.h"

ArchivoTrabajos::ArchivoTrabajos(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoTrabajos::Guardar(Trabajo trabajo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&trabajo, sizeof(Trabajo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoTrabajos::Guardar(Trabajo trabajo, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Trabajo) * posicion, SEEK_SET);
    bool ok = fwrite(&trabajo, sizeof(Trabajo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoTrabajos::Buscar(int IDtrabajo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Trabajo trabajo;
    int i = 0;
    while(fread(&trabajo, sizeof(Trabajo), 1, pArchivo)){
        if(trabajo.getIDTrabajo() == IDtrabajo){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Trabajo ArchivoTrabajos::Leer(int posicion){
    Trabajo trabajo;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return trabajo;
    }
    fseek(pArchivo, sizeof(Trabajo) * posicion, SEEK_SET);
    fread(&trabajo, sizeof(Trabajo), 1, pArchivo);
    fclose(pArchivo);
    return trabajo;
}

int ArchivoTrabajos::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Trabajo);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoTrabajos::Leer(int cantidadRegistros, Trabajo *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Trabajo), 1, pArchivo);
    }
    fclose(pArchivo);
}
