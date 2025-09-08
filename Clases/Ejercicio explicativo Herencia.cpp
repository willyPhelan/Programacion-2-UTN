#include <iostream>
#include <cstring>

using namespace std ;

class Fecha{

 private:

    int dia, mes, anio ;

    public:

    Fecha (int _dia=0, int _mes=0, int _anio=0){ // CONSTRUCTOR

    dia = _dia ;
    mes = _mes ;
    anio = _anio ; }

    void cargar() {

        cout << "Dia: " ;
        cin >> dia ;

        cout << "Mes: " ;
        cin >> mes ;

        cout << "Anio: " ;
        cin >> anio ;
    }

    void mostrar() {

        if(esCorrecta()){ cout << dia << "/" << mes << "/" << anio ; } else { cout << "Fecha incorrecta" << endl ;}

    }

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

    bool Fecha::esCorrecta() {
    if (anio <= 0) return false;       // año válido
    if (mes < 1 || mes > 12) return false;  // mes válido
    if (dia < 1 || dia > 31) return false;  // día entre 1 y 31 (sin diferenciar meses)

    return true; // si pasó las 3 validaciones, la fecha se considera correcta
}



    class Persona {

        private:
            char nombre[30], apellido[30], email[40] ;
            int dni ;

            Fecha fechaNacimiento ;  // instancio un objeto a travez de la clase Fecha

        public:

            void cargar() ;
            void mostrar() ;

            //getters

            const char *getNombre(){ return nombre ;}
            const char *getApellido(){return apellido ;}
            int getDni(){return dni ; }
            Fecha getFechaNacimiento(){ return fechaNacimiento ;}

            // setters

            void setNombre(const char *n){ strcpy(nombre, n) ;} // puntero para recibir la posicion en memoria del primer elemento del vector de caracteres y strcpy para copiar el contenido
            void setApellido(const char *n){ strcpy(apellido, n) ;}
            void setDni(int doc){ dni = doc ;}
            void setFechaNacimiento(Fecha fn){fechaNacimiento = fn ;} // se recibe el parametro fn de la clase Fecha


            }; // FIN CLASE PERSONA (CLASE BASE)

            // DEFINICION DE METODOS

            void Persona::cargar(){

            cout << endl << "Nombre: " << endl ;
            cin >> nombre ;

            cout << "Apellido: " << endl ;
            cin >> apellido ;

            cout << "DNI: " << endl  ;
            cin >> dni ;

            cout << "Fecha de nacimiento: " << endl ;
            fechaNacimiento.cargar(); // composicion -- Persona recibe la fecha de nacimiento de la clase Fecha por lo que debe acceder al valor mediante los metodos definidos en Fecha

            }

            void Persona::mostrar(){

            cout << endl << "Nombre: " << nombre << endl ;

            cout << "Apellido: " << apellido << endl ;

            cout << "DNI: " << dni << endl ;

            cout << "Fecha de nacimiento: " << endl ;
            fechaNacimiento.mostrar() ;

            }


            // CLASES DERIVADAS //


        class Alumno: public Persona{ // Alumno ES Persona // debo especificar de que manera quiero que alumno herede lasa props de la clase base, si public o private, por defecto las hereda de modo private. Esto no permite que se pueda acceder sa las props por fuera de la clase, como en main por ejemplo

        // utilizando public especifico que quiero que las porps de la clase base sean derivadas de manewra public. Por defecto las props se heredan de manera private

    private:

        int legajoAlumno ;
        int idCarrera ;

    public:

        // getter

        int getLegajo(){ return legajoAlumno ;}
        int getIdCarrera(){ return idCarrera ; }

        // setters // setters recibren el valor que asignaran a la propiedad por parametro

        void setLegajo(int legajo){legajoAlumno = legajo ; }
        void setIdCarrera(int id){ idCarrera = id ; }

        void mostrar() ;
        void cargar() ;
        int devolverLegajo(){return getLegajo();}

         } ; // FIN CLASE DERIVADA ALUMNO

         void Alumno::cargar(){

             Persona::cargar() ; // utilizo el metodo heredado de la clase Persona en la clase Alumno para cargar los demas datos

             cout << "Legajo:" << endl ;
             cin >> legajoAlumno ;

             cout << "ID de Carrera:" << endl ;
             cin >> idCarrera ;
             } ;

         void Alumno::mostrar(){


            Persona::mostrar() ;

            cout << endl << "Legajo: " << legajoAlumno << endl;
            cout << "ID de carrera:"  <<  idCarrera << endl ;

          } ;



int main() {

 Alumno obj ;

 /*

 obj.setNombre("Guillermo") ;
 obj.setLegajo(223376) ;

 cout << "Legajo: " << obj.getLegajo() << endl  ;
 cout << "Nombre: " << obj.getNombre() << endl  ;

 */

 obj.cargar() ;
 obj.mostrar() ;

 system("pause") ;

 return 0 ;

}
