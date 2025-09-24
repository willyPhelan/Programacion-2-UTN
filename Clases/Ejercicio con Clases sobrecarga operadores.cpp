# include<iostream>
# include<cstring>

///Hacer una clase de nombre Cadena para almacenar palabras,
///que ajuste su tama�o a la cantidad de caracteres estrictamente necesarios

using namespace std;

class Cadena{

private:

    char *p ;

    int tam ;


public:

    Cadena(const char *texto="NADA"){

        tam=strlen(texto) +1 ;

        p=new char[tam] ;

        if(p==nullptr)exit(1) ;

        strcpy(p,texto) ;

        p[tam-1]='\0' ;
    }

    Cadena(const Cadena &aux){

        if(this!=&aux){

            tam=aux.tam ;

            p=new char[tam] ;

            if(p==nullptr)exit(1) ;

            strcpy(p,aux.p) ;

            p[tam-1]='\0' ;
        }
    }

    void Mostrar(){

        cout << p <<endl ;
    }

    int getTamanio(){ return tam ; }

    const char *getP(){ return p ; }


    ///SOBRECARGAS

    bool operator == (Cadena aux) ;

    Cadena & operator=(Cadena aux) ;

    ///void operator=(string aux);

    void operator=(const char* aux);

    char operator[](int pos);

    bool operator == (const int numero) const ;  // Comparar con un entero

    bool operator == (const string &frase ) const ; // es const porque no se modifica el parametro recibido

    ///FIN SOBRECARGAS

    ~Cadena(){

        delete []p ;

    }
};

///desarrollo de m�todos
///sobrecargas

bool Cadena::operator==(Cadena aux){

    if(strcmp(p, aux.p)==0) return true ;

    return false ;

}

Cadena & Cadena::operator=(Cadena aux){

    delete []p ;

    tam=aux.tam ;

    p=new char[tam] ;

    if(p==nullptr)exit(1) ;

    strcpy(p,aux.p) ;

    return *this ;
}

void Cadena::operator=(const char* aux){

    delete []p ;

    tam= strlen(aux) +1 ;

    p=new char[tam] ;

    if(p==nullptr)exit(1) ;

    strcpy(p,aux) ;

}

char Cadena::operator[](int pos){

    if(pos >= 0 && pos < tam) return p[pos] ;

    return '\0' ;
}

// Sobrecarga del operador == para comparar con un n�mero

bool Cadena::operator==(int numero) const {

    return tam  -1 == numero ;
}

// Sobrecarga del operador == para comparar con un std::string

bool Cadena::operator==(const string &texto) const {

    // Compara el contenido de la cadena interna con el string recibido

    return strcmp(p, texto.c_str()) == 0 ;
}


///fin m�todos


int main(){

    Cadena c1("Hola mundo") ;

    if (c1 == 10){ // true,

        cout << "c1 tiene 10 caracteres\n" ; } else { cout << "No coincide" << endl ; }


    if (c1 == std::string("Hola mundo")) {


    cout << "Las cadenas son iguales \n" ; } else { cout << "No coinciden \n" ; }




  //  Cadena palabra("HOLA A TODOS/AS!"), otra("CHAU!"), ultima("veremos si funciona");
    /*palabra.Mostrar();
    if(palabra==otra){
        cout<<"IGUALES"<<endl;
    }
    else{
        cout<<"DISTINTAS"<<endl;
    }
    otra=palabra;
    if(palabra==otra){
        cout<<"IGUALES"<<endl;
    }
    else{
        cout<<"DISTINTAS"<<endl;
    }

    palabra="algo de manera directa";
    palabra.Mostrar();
    */
/*    palabra=otra=ultima;

    palabra.Mostrar();
    otra.Mostrar();
    ultima.Mostrar();

    cout<<ultima[3]<<endl;
    cout<<endl; */


	system("pause") ;

	return 0 ;
}
