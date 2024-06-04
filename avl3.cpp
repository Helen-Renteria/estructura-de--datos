#include <iostream>
#include <string>
#include <malloc.h>
#include <cstring> // libreria para copiar los datos de un string a un char 
#include <sstream> // libreria para convertir un string a entero 
#include <queue> 
using namespace std;
//creamos la estuctura con los datos para el pasajero
struct pasajero {
    char nombre[30]; 
    pasajero* siguiente; 
};
struct pasajero *nuevoPasajero;


struct nodo {
   int precioV;
    char destinoV [30];
    char  matriculaE[30];
    char nombreE [30];
    int DD; 
    int MM;
    int AA;
    int capacidadE; 
    int identificador;
    nodo *izq;
    nodo *der;
    int altura;
    pasajero* primerPasajero=NULL; // Apunta al primer pasajero del viaje
    pasajero* ultimoPasajero= NULL; // Apunta al último pasajero del viaje
    int numPasajeros; // Número de pasajeros en el viaje
};
struct nodo *raiz, *aux;


int obtenerAltura(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return n->altura;
}

int mayor(int a, int b) {
    return (a > b) ? a : b;
}

int obtenerBalance(struct nodo *n) {
    if (n == NULL) {
        return 0;
    }
    return obtenerAltura(n->izq) - obtenerAltura(n->der);
}



struct nodo* rotarDerecha(struct nodo *y) {
    struct nodo *x = y->izq;
    struct nodo *T2 = x->der;

    x->der = y;
    y->izq = T2;

    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;
    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;

    return x;
}

struct nodo* rotarIzquierda(struct nodo *x) {
    struct nodo *y = x->der;
    struct nodo *T2 = y->izq;

    y->izq = x;
    x->der = T2;

    x->altura = mayor(obtenerAltura(x->izq), obtenerAltura(x->der)) + 1;
    y->altura = mayor(obtenerAltura(y->izq), obtenerAltura(y->der)) + 1;

    return y;
}

int crearNodo() {
     
    string concatenar; 
    int concatenar2; 
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"Ingrese el precio del viaje: "<<endl;
    cin>>aux->precioV;
    cout<<"Ingrese el destino del viaje: "<<endl;
    cin>>aux->destinoV;
    cout<<"Ingrese la matricula de la embarcacion (numero enteros): "<<endl;
    cin>>aux->matriculaE;
    cout<<"Ingrese el nombre de la embarcacion: "<<endl;
    cin>>aux->nombreE;
    cout<<"Ingrese la fecha del viaje: "<<endl;
    cout<<"DIA"<<endl;
    cin>>aux->DD;
    cout<<"MES"<<endl;
    cin>>aux->MM;
    cout<<"AA"<<endl;
    cin>>aux->AA;
    cout<<"Ingrese la capacidad de la embarcacion: "<<endl;
    cin>>aux->capacidadE; 
     
  // creamos el identificador unico 

    // creamos una nueva variable para guardar los 2 primeros caracteres  
    string primerosCart = string(aux-> matriculaE, 2);
    concatenar = primerosCart + to_string(aux->AA) + to_string(aux->MM) + to_string(aux->DD);
    
    stringstream(concatenar) >> concatenar2; // Convertimos el string a entero
   
    aux->identificador = concatenar2; 
    cout<<"su identificador unico es "<< aux->identificador<<endl;
    


    aux->izq = NULL;
    aux->der = NULL;
    aux->altura = 1;  
    return 0;   
}
// el arbol se esta organizando por el identificador 
struct nodo* insertar(struct nodo* nodo) {
    if (nodo == NULL) {
        return aux;
    }

    if (aux->identificador < nodo->identificador) {
        nodo->izq = insertar(nodo->izq);
    } else if (aux->identificador > nodo->identificador) {
        nodo->der = insertar(nodo->der);
    } else {
        return nodo;
    }

    nodo->altura = 1 + mayor(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && aux->identificador < nodo->izq->identificador) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->identificador > nodo->der->identificador) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && aux->identificador > nodo->izq->identificador) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->identificador < nodo->der->identificador) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;
}




void inOrden(struct nodo *nodo){
    if (nodo-> izq!=NULL){
     inOrden(nodo->izq);
    }

        cout<<"*"<<endl;
        cout<<"Precio del viaje: "<<nodo->precioV<<endl;
        cout<<"Destino del viaje: "<<nodo->destinoV<<endl;
        cout<<"Matricula de la embarcacion: "<<nodo->matriculaE<<endl;
        cout<<"Nombre de la embarcacion: "<<nodo->nombreE<<endl;
        cout<<"AA"<<nodo->AA<<endl;
        cout<<"MES"<<nodo->MM<<endl;
        cout<<"DIA"<<nodo->DD<<endl;
        cout<<"Capacidad de la embarcacion: "<<nodo->capacidadE<<endl;
        cout<<"Identicicador: "<<nodo->identificador<<endl;
        cout<<"*"<<endl;
    if(nodo->der!=NULL){
     inOrden(nodo->der);
    }


 }

bool buscar(nodo *arbol , int n, nodo *&encontrado){
    
    if (arbol == NULL){
        return  false;
    }
    else if (arbol->identificador == n){
        encontrado = arbol; 
        return true;
    }
    else if (n < arbol->identificador){
   
          cout << "Buscando en el lado izquierdo." << endl;//mesaje para ver si esta buacando en este lado del arbol
       return buscar(arbol->izq, n, encontrado);
    }else{
      
          cout << "Buscando en el lado derecho" << endl;// "   "  "
        return buscar(arbol->der, n, encontrado);
    }  
    }
    
// metodo eliminar 
int ubicar(nodo *aux3, int aguja){
    if (aux3->identificador == aguja ){
        aux = aux3;
        return 1;
    }
    else{
        if(aux3->izq!=NULL){
            ubicar(aux3->izq, aguja);
        }
        if(aux3->der!=NULL){
            ubicar(aux3->der, aguja); 
        }
    }

return 0;
}
int ubicarPadre(nodo *padre){
    if ((padre-> izq!=NULL) && (padre->izq!=aux)){
       ubicarPadre(padre->izq);
    }
    if(padre->izq == aux){
        raiz = padre; 
    }
    if ((padre-> der!=NULL)&& (padre->der!=aux)){
       ubicarPadre(padre->der);
    }
    if(padre->der == aux){
        raiz = padre; 
    }
    return 0; 
    
}

//cuando no tiene hijos
int casoUno(){
    if( aux!=raiz){
    ubicarPadre(raiz);
    } 
    if(raiz->izq==aux){
        raiz->izq =NULL;
    }
    else if (raiz->der==aux){
        raiz->der = NULL;
    }
    free(aux); 
    cout<<"---elemento eliminado...."<<endl;
    return 0;

}
// cuando tiene un hijo
int casoDos(){
    if( aux!=raiz){
     ubicarPadre(raiz);
    } 
   if(raiz->izq==aux){
        if(aux->izq!=NULL)
          raiz->izq = aux->izq;
          else if(aux->der!=NULL)
          raiz->izq = aux->der;
       
    }
    else if (raiz->der==aux){
        if(aux->izq!=NULL)
            raiz->der = aux->izq;
          else if(aux->der!=NULL)
          raiz->der = aux->der;
    }
    free(raiz); 
    cout<<"---elemento eliminado...."<<endl;
    return 0;

}
int casoTres(){
    nodo* padre= aux;
    nodo *sucesor = aux->der;
    //buscamos el sucesor 
    while(sucesor ->izq!=NULL){
        padre = sucesor;
        sucesor = sucesor->izq;
    }
    aux->identificador= sucesor->identificador;
    if(padre==aux){
        aux->der = sucesor->der; 
    }else{
        padre->izq = sucesor->der;
    }
    free(sucesor);
    cout<<"---elemento eliminado...."<<endl;
    return 0; 
}


 struct nodo* eliminar (struct nodo* nodo){
    int buscar;
    cout<<"Digite el identificador de el viaje que desea eliminar: "<<endl;
    cin>>buscar; 
    ubicar(raiz, buscar);

      if (aux == NULL) {
        cout << "Viaje no encontrado." << endl;
        return nodo;
    }
    if ((aux->der == NULL)&& (aux->izq == NULL)){
        casoUno();

        }
    else if(((aux->der == NULL)&& (aux->izq != NULL))||((aux->der != NULL)&& (aux->izq == NULL))){
        casoDos();
    }
    else{
        casoTres();
    }



    nodo->altura = 1 + mayor(obtenerAltura(nodo->izq), obtenerAltura(nodo->der));

    int balance = obtenerBalance(nodo);

    if (balance > 1 && aux->identificador < nodo->izq->identificador) {
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->identificador > nodo->der->identificador) {
        return rotarIzquierda(nodo);
    }

    if (balance > 1 && aux->identificador > nodo->izq->identificador) {
        nodo->izq = rotarIzquierda(nodo->izq);
        return rotarDerecha(nodo);
    }

    if (balance < -1 && aux->identificador < nodo->der->identificador) {
        nodo->der = rotarDerecha(nodo->der);
        return rotarIzquierda(nodo);
    }

    return nodo;


     
    
}



// metodo para registrar el pasajero 
void registrar_pasajero(nodo* RegistrarP, int identificador) {
    char nombrePasajero[30];
    nodo* viaje = NULL; 
    buscar(RegistrarP, identificador, viaje);
    cout<<"comprobante "<<viaje->identificador<<endl;
    
    if (viaje != NULL) {
        if (viaje->numPasajeros < viaje->capacidadE) {
            nuevoPasajero =(( struct pasajero*)malloc(sizeof( struct pasajero)));
                      
            cout <<"ingrese el nombre del pasajero: "<<endl; 
            cin>>nuevoPasajero->nombre;
            nuevoPasajero->siguiente = NULL;
            if (viaje->primerPasajero == NULL) {
                viaje->primerPasajero = nuevoPasajero;
                viaje->ultimoPasajero = nuevoPasajero;
            } else {
                viaje->ultimoPasajero->siguiente = nuevoPasajero;
                viaje->ultimoPasajero = nuevoPasajero;

            }
            viaje->numPasajeros++;
            cout << "\nPasajero registrado con Exito.\n";
        } else {
            cout << "\nNo hay capacidad disponible en este viaje.\n";
        }
    } else {
        cout << "\nViaje no encontrado.\n";
    }
}

void mostrarPasajeros(nodo* viaje) {
    if (viaje == NULL || viaje->primerPasajero == NULL) {
        cout << "No hay pasajeros registrados en este viaje." << endl;
        return;
    }

    pasajero* actual = viaje->primerPasajero;
    cout << "Pasajeros registrados en el viaje " << viaje->identificador << ":" << endl;
    while (actual != NULL) {
        cout << "- " << actual->nombre << endl;
        actual = actual->siguiente;
    }
}


int main() {
     nodo *encontrado = NULL; 
    raiz = NULL;
    int opc = 0;
    int ID;
    
    do {
        cout<<"Menu de opciones"<<endl;
        cout<<"1. Registrar un nuevo viaje."<<endl;
        cout<<"2. Listar todos los viajes"<<endl;
        cout<<"3. buscar un viaje por identificador."<<endl;
        cout<<"4. Eliminar un viaje por identificador. "<<endl;
        cout<<"5. Registrar un pasajero en un viaje."<<endl;
        cout<<"6. Listar todos los pasajeros de un viaje. "<<endl;
        cout<<"7. salir"<<endl;
        cin>>opc;
        switch (opc) {
            case 1:
                crearNodo();
                raiz = insertar(raiz);
                break;
            case 2:
                cout<<"PreOrden: ";
                inOrden(raiz); 
                cout<<endl;
                break;
            case 3: 
            cout<<"Ingrese el identificador unico del viaje que decea buscar: "<<endl;
                cin>>ID;
                encontrado = NULL; 
                if(buscar(raiz , ID,encontrado)){
        cout<<""<<endl;
        cout<<"Precio del viaje: "<<encontrado->precioV<<endl;
        cout<<"Destino del viaje: "<<encontrado->destinoV<<endl;
        cout<<"Matricula de la embarcacion: "<<encontrado->matriculaE<<endl;
        cout<<"Nombre de la embarcacion: "<<encontrado->nombreE<<endl;
        cout<<"AA"<<encontrado->AA<<endl;
        cout<<"MES"<<encontrado->MM<<endl;
        cout<<"DIA"<<encontrado->DD<<endl;
        cout<<"Capacidad de la embarcacion: "<<encontrado->capacidadE<<endl;
        cout<<"Identicicador: "<<encontrado->identificador<<endl;
        cout<<""<<endl;
                }

                else{
                    cout<<"elemento NO encontrado"<<endl; 
                }
                

                 break;

            case 4: 

            eliminar(raiz);
            break;
            
            case 5:
             cout << "Ingrese el identificador del viaje donde desea registrar un pasajero: ";
                cin >> ID;
             
            registrar_pasajero(raiz, ID);
                
                break;

            case 6:
              cout << "Ingrese el identificador del viaje donde desea mostrar los pasajeros: ";
                cin >> ID;
              encontrado = NULL;
              if (buscar(raiz, ID, encontrado)) {
               mostrarPasajeros(encontrado);
    } else {
        cout << "Viaje no encontrado." << endl;
    }
    break;
    
        }
    } while (opc != 7);
return 0;
}
 /* INTEGRANTES
 HELEN FARINA RENTERIA RENTERIA
 PAOLA ANDREA SINISTERRA MOSQUERA 
 */