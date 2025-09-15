#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "funciones.h"

using namespace std ;

bool escribirRegistroSocio(Socio reg) {

    FILE* pSocio = fopen("socios.dat", "ab") ;

    if (pSocio == nullptr) return false ;

    bool escribio = fwrite(&reg, sizeof(Socio), 1, pSocio) ;

    fclose(pSocio) ;

    return escribio ;
}

bool mostrarRegistroSocio() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        reg.mostrar() ;

        cout << "------------------------\n" ;
    }

    fclose(pSocio) ;

    return true ;
}

bool mostrarRegistroPorDNI(int dni) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    bool encontrado = false ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getDNI() == dni) {

            cout << "\nSocio encontrado:\n" ;

            reg.mostrar() ;

            encontrado = true ;

            break ;
        }
    }

    fclose(pSocio) ;

    if (!encontrado) cout << "No existe socio con ese DNI\n" ;

    return encontrado ;
}

bool agregarRegistroSocio() {

    Socio nuevoSocio ;

    nuevoSocio.cargar() ;

    int id = nuevoSocio.getIdSocio() ;

    int dni = nuevoSocio.getDNI() ;

    int posReg = buscarRegistroSocio(id) ;

    bool dniExiste = existeDNI(dni) ;

    if (posReg != -1 || dniExiste) {

        cout << "\nNo se puede repetir el ID ni el DNI.\n" ;

        return false ;
    }

    return escribirRegistroSocio(nuevoSocio) ;
}

int buscarRegistroSocio(int idSocio) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return -1 ;

    Socio reg ;

    int pos = 0 ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getIdSocio() == idSocio) {

            fclose(pSocio) ;

            return pos ;
        }
        pos++ ;
    }
    fclose(pSocio) ;

    return -1 ;
}

int contarRegistrosSocios() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return 0 ;

    Socio reg ;
    int contador = 0 ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        contador++ ;
    }
    fclose(pSocio) ;

    return contador ;
}

int contarRegistrosSocios2() {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return -1 ;

    fseek(pSocio, 0, SEEK_END) ;

    int cantBytes = ftell(pSocio) ;

    fclose(pSocio) ;

    return cantBytes / sizeof(Socio) ;
}

void buscarSocioPorId() {

    int idSocio;

    cout << "Ingrese el ID del socio que desea buscar: " ;
    cin >> idSocio ;

    int pos = buscarRegistroSocio(idSocio) ;

    if (pos == -1) {

        cout << "No existe socio con ese ID\n" ;

        return ;
    }

    Socio reg = leerRegistroSocio(pos) ;

    cout << "\nSocio encontrado:\n" ;

    reg.mostrar() ;
}

Socio leerRegistroSocio(int posReg) {

    Socio reg ;

    reg.setIdSocio(-1) ;

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return reg ;

    int pos = 0 ;
    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (pos == posReg) {

            fclose(pSocio) ;

            return reg;

        }

        pos++ ;
    }

    fclose(pSocio) ;

    reg.setIdSocio(-1) ;

    return reg ;
}

Socio leerRegistroSocio2(int posReg) {

    Socio reg ;

    reg.setIdSocio(-1) ;

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return reg ;

    fseek(pSocio, posReg * sizeof(Socio), SEEK_SET) ;

    fread(&reg, sizeof(Socio), 1, pSocio) ;

    fclose(pSocio) ;

    return reg;
}

bool existeDNI(int dni) {

    FILE* pSocio = fopen("socios.dat", "rb") ;

    if (pSocio == nullptr) return false ;

    Socio reg ;

    while (fread(&reg, sizeof(Socio), 1, pSocio)) {

        if (reg.getDNI() == dni) {

            fclose(pSocio) ;

            return true ;
        }
    }

    fclose(pSocio) ;

    return false ;
}

void menu() {

    int opcion ;

    do {
        system("cls") ;

        cout << "=== MENU SOCIOS ===\n" ;
        cout << "1. Agregar registro\n" ;
        cout << "2. Buscar registro por DNI\n" ;
        cout << "3. Buscar registro por ID de socio\n" ;
        cout << "4. Listar todos los registros\n" ;
        cout << "5. Contar todos los registros\n" ;
        cout << "0. Salir\n" ;
        cout << endl <<"Ingrese opcion: " ;

        cin >> opcion ;

        switch (opcion) {

        case 1:

            system("cls") ;

            cout << "--- AGREGAR REGISTRO ---\n" << endl ;

            if (agregarRegistroSocio())

                cout << "Registro agregado correctamente.\n" ;

            else
                cout << "No se pudo agregar el registro.\n" ;

            system("pause") ;

            break ;

        case 2 :

            system("cls") ;

            cout << "--- MOSTRAR REGISTRO POR DNI ---\n" ;
            int dniBuscar ;

            cout << "Ingrese DNI a buscar: " ;
            cin >> dniBuscar ;

            mostrarRegistroPorDNI(dniBuscar) ;

            system("pause") ;

            break ;

        case 3:

            system("cls") ;

            cout << "--- BUSCAR SOCIO POR ID ---\n" ;

            buscarSocioPorId() ;

            system("pause") ;

            break ;

        case 4:

            system("cls") ;

            cout << "--- LISTADO DE TODOS LOS SOCIOS ---\n" << endl ;

            if (!mostrarRegistroSocio())

                cout << "No hay registros cargados.\n" ;

            system("pause") ;

            break ;

        case 5:

            system("cls") ;

            cout << "CANTIDAD DE SOCIOS: " << contarRegistrosSocios2() << endl ;

            system("pause") ;

            break ;

        case 0:

            cout << "Saliendo...\n" ;

            break ;

        default:

            cout << "Opcion invalida.\n" ;

            system("pause") ;

            break ;
        }

    } while (opcion != 0) ;
}
