#include <iostream>

using namespace std ;

class Fecha { // defino una clase fecha

    private: // en private defino las props de la clase para que no puedan ser modificadas directamente

    int dia, mes, anio ;   // cada obj que cree mediante esta clase, tendra las propiedades dia, mes y anio

    public:  // aca van los metodos que definen el comportamiento de la clase y mediante el cual podemos modificar las porps de private

    void cargar() ; // si defino el metodo FUERA de la clase, debo llamarla dentro

    void mostrar(){ // // metodo definido DENTRO DE LA CLASE

        cout << dia << "/" << mes << "/" << anio << endl ;
    }

    // CONSTRUCTORES: METODOS DENTRO DE LA CLASE QUE NOS PERMITEN DAR VALORES INICIALES A LAS PROPIEDADES DE LOS OBJETOS

    Fecha (int _dia, int _mes, int _anio){

    dia = _dia ;
    mes = _mes ;
    anio = _anio ; }

    Fecha() { // puedo tener varios constructores mientras que se diferencien por sus parametros

    dia = 0 ;
    mes = 0 ;
    anio = 0 ;

    } // mediante estos dos constructores se crearan dos objetos uno con los valores iniciales pasados por parametro y el otro con todas sus propiedades inicializadas en 0


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

    bool esCorrecta(){

    if(dia != -1 && mes != -1 && anio != -1) return true ;
    return false ; }

    ~Fecha(){ // DESTRUCTOR PARA ELIMINAR EL OBJ Y LIBERAR MEMORIA

        cout << "Se murio el objeto" << endl ;
    }

    } ; // FIN DE LA CLASE

    // metodo definido FUERA de la clase // puedo hacerlo asi pero debo especificar con :: a que clase pertenece (tipo de funcion + clase + metodo

   void Fecha::cargar(){ // metodo , que a diferencia de las funciones comunes, no necesitan ser dedclaradas porque son parte de la propia clase

        int _dia, _mes, _anio ;

        cout << "Ingresar el dia:" << endl ;
        cin >> _dia ;
        setDia(_dia) ; // mediante SETTERS asigno el valor que definio el usuario

        cout << "Ingresar el mes:" << endl ;
        cin >> _mes ;
        setMes(_mes) ;

        cout << "Ingresar el anio:" << endl ;
        cin >> _anio ;
        setAnio(_anio) ;

        cout << endl ;

        }

//  LOS OBJETOS SOLO PUEDEN LLAMAR METODOS QUE ESTEN IMPLEMENTADOS DENTRO DE SUS CLASES NO PUEDEN LLAMAR FUNCIONES EXTERNAS.

int main() {

    Fecha hoy(14,6,1996), ayer ; // mediante la clase Fecha puedo crear el objeto hoy que tendra todas las props y metodos definidos en dicha clase // al obj hoy le puedo definir valores iniciales gracias al constructor que los define

  //  hoy.cargar() ; comento estec metodo porque estoy utilizando el primer constructor

    // determino fecha mediante setters de manera manual

   // hoy.setDia(11) ;
  //  hoy.setMes(8) ;
  //  hoy.setAnio(2000) ;

    if(hoy.esCorrecta())hoy.mostrar()  ; // esCorrecta es un metodo para validar
    else { cout << "Fecha incorrecta" << endl ; }

    // muestro fecha mediante getters

    if(hoy.getDia() == 21) cout << endl << "EL dia es 21" << endl ;

    ayer.mostrar() ; // devolvera 0/0/0 porque son los valores iniciales definidos en uno de los constructores

   cout << endl ;

    system("pause") ;
    return 0 ;

}
