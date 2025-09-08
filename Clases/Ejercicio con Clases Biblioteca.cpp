/* Enunciado base para determinar objetos/clases

Una biblioteca lleva el registro de los socios, los libros que tiene y los préstamos de
libros que realiza a los socios.

Por cada uno de los socios registra el DNI, el nombre, el apellido, un número de
teléfono, un email, la fecha de nacimiento y la dirección.

De la dirección se registra la calle, el número y la localidad. Por razones administrativas a cada una de las personas
que se asocia se le asigna además un número único que lo identifica como socio.

Para cada libro se registra el número ISBN, el nombre del libro, el nombre del autor, la
fecha de publicación, y la cantidad de ejemplares de ese libro que tiene la biblioteca.

El número ISBN (International Standard Book Number) es un código numérico que
identifica de forma única a cada libro publicado.

En cuanto a cada uno de los préstamos, a la Biblioteca le interesa saber cuál es el libro
que se prestó, a qué socio se lo prestó, cuál fue el día del préstamo y cuál fue la fecha
de devolución.

A partir de la descripción se pide:

• Definir cuáles son los objetos que se necesitan para registrar la información de
la biblioteca.

• Para cada uno de los objetos, definir cuáles son las propiedades necesarias.

• Definir el tipo de dato que corresponda para representar cada propiedad.

• Hacer las clases correspondientes  */

#include <iostream>

using namespace std ;


class Fecha{

 private:

    int dia, mes, anio ;

    public:

    Fecha (int _dia=0, int _mes=0, int _anio=0){ // CONSTRUCTOR

    dia = _dia ;
    mes = _mes ;
    anio = _anio ; }

    void cargar() ;

    void mostrar() ;

      // SETTERS metodos dentro de la clase que se utilizan para dar valor a cada una de las props

    void setDia(int d){

    if(d >= 1 && d <= 31) dia = d ; // validacion }

    else dia = -1 ;

    } ;

    void setMes(int m){

    if(m >= 1 && m <= 12) mes = m ;

    else mes = -1 ;

    }

    void setAnio(int a){

    if(a> 0) anio = a ;

    else anio = -1 ;

    }

    // GETTERS devuelven los valores de las propiedades de los objs

    int getDia(){ return dia ; }
    int getMes(){ return mes ; }
    int getAnio(){ return anio ; }

    bool esCorrecta();

    }; // FIN CLASE FECHA

    void Fecha::cargar() {

    cout << "Ingrese el dia: ";
    cin >> dia;
    cout << "Ingrese el mes: ";
    cin >> mes;
    cout << "Ingrese el anio: ";
    cin >> anio;
}

void Fecha::mostrar() {
    cout << dia << "/" << mes << "/" << anio << endl;
}


    class Direccion{

    private:
        char calle[30] ;
        int numero ;
        char localidad[30] ;

    public:

        void cargar() ;
        void mostrar() ;


} ; // FIN CLASE DIRECCION

class Socio {

    private:

        int dni, idSocio ;
        char nombre[30], apellido[30] ; // para representar un numero
        char telefono[15], email[40] ;

        Fecha fechaNacimiento ; // clase Fecha, obj fechaNacimiento
        Direccion domicilio ; // clase Direccion, domicilio ;


    public:

        void cargar() ;
        void mostrar() ;

        // GETTERS

        int getIdSocio(){ return idSocio ; }
        Fecha getFechaNacimiento(){return fechaNacimiento ; }
        Direccion getDomicilio(){return domicilio ;} ;

        // SETTERS

        void setIdSocio(int id){idSocio = id ; }  ;
        void setFechaNacimiento(Fecha nac){fechaNacimiento = nac ;} // recibe el parametro de la clase Fecha
        void setDomicilio(Direccion dom){domicilio = dom ;} ;
        void setDiaNacimiento(int d){
        fechaNacimiento.setDia(d) ;}


    }; // FIN CLASE SOCIO


     void Direccion::cargar(){

        cout << "Ingrese la calle: "  ;
        cin >> calle ;

        cout << "Ingrese el numero: " ;
        cin >> numero ;

        cout << "Ingrese la localidad: " ;
        cin >> localidad ; }



    void Direccion::mostrar(){


        cout << "Calle: " << calle << endl ;

        cout << "Numero: " << numero << endl ;

        cout << "Localidad: " << localidad << endl ;

        }

    void Socio::cargar(){ // puedo definir los metodos fuera de la clase pero debo asociarlos a la clase que quiero que los tenga mediante los ::

    cout << "Ingrese el ID del socio: " ;
    cin >> idSocio ;

    cout << "Ingrese el nombre del socio: " ;
    cin >> nombre ;

    cout << "Ingrese el apellido del socio: " ;
    cin >> apellido;

    cout << endl << "Ingrese la fecha de nacimiento del socio: " ;
    fechaNacimiento.cargar();

    cout << endl << "Ingrese el domicilio del socio: " ;
    domicilio.cargar() ; // es un obj

    }


    void Socio::mostrar(){ // puedo definir los metodos fuera de la clase pero debo asociarlos a la clase que quiero que los tenga mediante los ::

    cout << endl <<  "Ingrese el ID del socio: " ;
    cin >> idSocio ;

    cout << "Ingrese el nombre del socio: "  ;
    cin >> nombre ;

    cout << "Ingrese el Apellido del socio: " ;
    cin >> apellido;

    cout << endl << "Ingrese la fecha de nacimiento del socio: " << endl   ;
    fechaNacimiento.cargar();

    cout << endl << "Domicilio del socio: " << endl;
    domicilio.mostrar() ; // es un obj


    // lo que esta definido en la parte private, no pude ser referenciada ni accedido de manera directa, debo utilizar los metodos y acceder desde el objeto que tieen ese metodo: fechaNacimiento cargar()

    // ENCAPSULAMIENTO: mecanismo que permite que una clase tenga como porpiedad obejtos de otra clase. NO puedo acceder directamente a estas propiedades debo usar los metodos de la clase a la que el obj pertenece

    }

int main() {

    Socio nuevo ;

    nuevo.cargar() ;

    cout << endl ;

    nuevo.mostrar() ;

    cout << endl ;

    system("pause") ;

    return 0 ;

}
