#include<iostream>
#include<malloc.h>
#include <string>
#include <cstring> // biblioteca para copiar la cadena de caracteres
//char* strcpy(char* destino, const char* origen);
using namespace std;

struct nodo{
    int codigo;
    char nombre[30];
    char apellido[30]; 
    int AA;
    int MM;
    int DD; 
    nodo *izq;
    nodo *der;
};

nodo *raiz=NULL, *aux=NULL, *aux2=NULL,*raiz2=NULL, *aux5=NULL, *nuevoNodoC=NULL, *nuevoNodoF=NULL;

int posicionarC(){
    if (nuevoNodoC->codigo < aux2->codigo){
        if(aux2->izq!=NULL){
            aux2 = aux2->izq;
            posicionarC();
        }
        else {
            aux2->izq = nuevoNodoC;
        } 
        
    }
    else if (nuevoNodoC ->codigo > aux2->codigo){
        if(aux2->der!=NULL){
            aux2 = aux2->der;
            posicionarC();
    }
        else {
        aux2->der = nuevoNodoC;
        }

    }
    return 0; 
}

int posicionarF(){
    if (nuevoNodoF->AA < aux5->AA){
        if(aux5->izq!=NULL){
            aux5 = aux5->izq;
            posicionarF();
        }
        else {
            aux5->izq = nuevoNodoF; 
        } 
    }
    else if (nuevoNodoF->AA > aux5->AA){
        if(aux5->der!=NULL){
            aux5 = aux5->der;
            posicionarF();
    }
        else {
        aux5->der = nuevoNodoF;
        }

    }
     else{
        //si los años son iguales, comparamos el mes
        if (nuevoNodoF->MM < aux5->MM){
        if(aux5->izq!=NULL){
            aux5 = aux5->izq;
            posicionarF();
        }
        else {
            aux5->izq = nuevoNodoF; 
        } 
    }
    else if (nuevoNodoF->MM > aux5->MM){
        if(aux5->der!=NULL){
            aux5 = aux5->der;
            posicionarF();
    }
        else {
        aux5->der = nuevoNodoF;
        }

    }else{
        // si el año y mes son iguales comparamos por dia 
        if (nuevoNodoF->DD < aux5->DD){
        if(aux5->izq!=NULL){
            aux5 = aux5->izq;
            posicionarF();
        }
        else {
            aux5->izq = nuevoNodoF; 
        } 
    }
    else {
        // sie l dia es igual o mayor insertamos a la derecha
        if(aux5->der!=NULL){
            aux5 = aux5->der;
            posicionarF();
    }
        else {
        aux5->der = nuevoNodoF;
        }
    }
    }
    }
    
    return 0; 
}
int registrarC(){
   
    //creamos variables temporales para guardar los datos
    int codigoIngresado;
    string nombreIngresado;
    string apellidoIngresado;
    int AAIngresado=0, MMIngresado=0, DDIngresado=0; 
    
    cout<<" ingrese su codigo: "<<endl;
    cin>>codigoIngresado;
    cout<<" ingrese su nombre: "<<endl;
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, nombreIngresado);
    cout<<" ingrese su apellido: "<<endl;
    getline(cin, apellidoIngresado);
    cout<<" ingrese su fecha de nacimiento "<<endl;
    cout<<" AA: "<<endl;
    cin>>AAIngresado;
    cout<<" MES: "<<endl;
    cin>>MMIngresado;
    cout<<" DIA: "<<endl;
    cin>>DDIngresado;
    cin.ignore();
    
   //guardamos los datos a los apuntadores por fecha y por codigo
   

   //fecha  
   nuevoNodoF = (struct nodo *) malloc(sizeof(struct nodo));
   nuevoNodoF->AA = AAIngresado;
   nuevoNodoF->MM = MMIngresado;
   nuevoNodoF->DD = DDIngresado;
   nuevoNodoF->codigo = codigoIngresado;
   strcpy( nuevoNodoF->nombre, nombreIngresado.c_str());
   strcpy(nuevoNodoF->apellido, apellidoIngresado.c_str()); 
  
   nuevoNodoF->izq = nuevoNodoF->der = NULL; 

    // organizar por fecha 
    if(raiz2 == NULL){
        raiz2= nuevoNodoF;
        
    }
    else{
        aux5 = raiz2; 
        posicionarF();

        
    }
     // organizar por codigo
    /*strcpy() copiará los caracteres de la cadena nombreIngresado y
     apellidoIngresado a los arrays de caracteres nuevoNodoF->nombre y 
     nuevoNodoF->apellido respectivamente.
    */
    //codigo
  nuevoNodoC = (struct nodo *) malloc(sizeof(struct nodo));
     
   nuevoNodoC->codigo = codigoIngresado;
   strcpy( nuevoNodoC->nombre, nombreIngresado.c_str());
   strcpy(nuevoNodoC->apellido, apellidoIngresado.c_str());
   nuevoNodoC->AA = AAIngresado;
   nuevoNodoC->MM = MMIngresado;
   nuevoNodoC->DD = DDIngresado;
   nuevoNodoC->izq = nuevoNodoC->der = NULL; 

    if(raiz == NULL){
        raiz= nuevoNodoC;
        
    }
    else{
        aux2 = raiz; 
        posicionarC();
        
    }     

     return 0; 
}

    
 int preOrden( nodo *aux3){
    cout<<"codigo: "<<aux3->codigo<<endl;
    cout<<"nombre: "<<aux3->nombre<<endl;
    cout<<"apellido: "<<aux3->apellido<<endl;
    cout<<"fecha de nacimiento: "<<endl;
    cout<<" AA: "<<aux3->AA<<endl;
    cout<<" MES: "<<aux3->MM<<endl;
    cout<<" DIA: "<<aux3->DD<<endl;

    if (aux3-> izq!=NULL){
    preOrden(aux3->izq);
    }
    if (aux3-> der!=NULL){  
    preOrden(aux3->der);
    }
    return 0;
 }
 

 int inOrden( nodo *aux3){
    if (aux3-> izq!=NULL){
     inOrden(aux3->izq);
    }
    cout<<"codigo: "<<aux3->codigo<<endl;
    cout<<"nombre: "<<aux3->nombre<<endl;
    cout<<"apellido: "<<aux3->apellido<<endl;
    cout<<"fecha de nacimiento: "<<endl;
    cout<<" AA: "<<aux3->AA<<endl;
    cout<<" MES: "<<aux3->MM<<endl;
    cout<<" DIA: "<<aux3->DD<<endl;
    if(aux3-> der!=NULL){
     inOrden(aux3->der);
    }

    return 0;
 }
  int postOrden( nodo *aux3){
    if (aux3-> izq!=NULL){
    postOrden(aux3->izq);
    }
    if (aux3-> der!=NULL){
    postOrden(aux3->der);
    }
    cout<<"codigo: "<<aux3->codigo<<endl;
    cout<<"nombre: "<<aux3->nombre<<endl;
    cout<<"apellido: "<<aux3->apellido<<endl;
    cout<<"fecha de nacimiento: "<<endl;
    cout<<" AA: "<<aux3->AA<<endl;
    cout<<" MES: "<<aux3->MM<<endl;
    cout<<" DIA: "<<aux3->DD<<endl;

    return 0;
 }

int ubicar(nodo *aux3, int aguja){
    if (aux3->codigo == aguja ){
        nuevoNodoC = aux3;
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

int ubicarF(nodo *aux3, int aguja){
    if (aux3->codigo == aguja ){
        nuevoNodoF = aux3;
        return 1;
    }
    else{
        if(aux3->izq!=NULL){
            ubicarF(aux3->izq, aguja);
        }
        if(aux3->der!=NULL){
            ubicarF(aux3->der, aguja); 
        }
    }

return 0;
}




int ubicarPadre(nodo *padre){
    if ((padre-> izq!=NULL) && (padre->izq!=nuevoNodoC)){
       ubicarPadre(padre->izq);
    }
    if(padre->izq == nuevoNodoC){
        aux2 = padre; 
    }
    if ((padre-> der!=NULL)&& (padre->der!=nuevoNodoC)){
       ubicarPadre(padre->der);
    }
    if(padre->der == nuevoNodoC){
        aux2= padre; 
    }
    return 0; 
    
}

int ubicarPadreF(nodo *padre){
    if ((padre-> izq!=NULL) && (padre->izq!=nuevoNodoF)){
       ubicarPadreF(padre->izq);
    }
    if(padre->izq == nuevoNodoF){
        aux5 = padre; 
    }
    if ((padre-> der!=NULL)&& (padre->der!=nuevoNodoF)){
       ubicarPadreF(padre->der);
    }
    if(padre->der == nuevoNodoF){
        aux5= padre; 
    }
    return 0; 
    
}

//cuando no tiene hijos
int casoUno(){
    if( nuevoNodoC!=raiz){
    ubicarPadre(raiz);
    } 
    if(aux2->izq==nuevoNodoC){
        aux2->izq =NULL;
    }
    else if (aux2->der==nuevoNodoC){
        aux2->der = NULL;
    }
    free(nuevoNodoC); 
    return 0;

}

int casoUnoF(){
    if( nuevoNodoF!=raiz2){
    ubicarPadreF(raiz2);
    } 
    if(aux5->izq==nuevoNodoF){
        aux5->izq =NULL;
    }
    else if (aux5->der==nuevoNodoF){
        aux5->der = NULL;
    }
    free(nuevoNodoF); 
    return 0;
}

// cuando tiene un hijo
int casoDos(){
    if( nuevoNodoC!=raiz){
     ubicarPadreF(raiz);
    } 
   if(aux2->izq==nuevoNodoC){
        if(nuevoNodoC->izq!=NULL)
          aux2->izq = nuevoNodoC->izq;
          else if(nuevoNodoC->der!=NULL)
           aux2->izq = nuevoNodoC->der;
       
    }
    else if (aux2->der==nuevoNodoC){
        if(nuevoNodoC->izq!=NULL)
            aux2->der = nuevoNodoC->izq;
          else if(nuevoNodoC->der!=NULL)
           aux2->der = nuevoNodoC->der;
    }
    free(nuevoNodoC); 
    return 0;

}

// cuando tiene un hijo
int casoDosF(){
    if( nuevoNodoF!=raiz2){
     ubicarPadreF(raiz2);
    } 
   if(aux5->izq==nuevoNodoF){
        if(nuevoNodoF->izq!=NULL)
          aux5->izq = nuevoNodoF->izq;
          else if(nuevoNodoF->der!=NULL)
           aux5->izq = nuevoNodoF->der;
       
    }
    else if (aux5->der==nuevoNodoF){
        if(nuevoNodoF->izq!=NULL)
            aux5->der = nuevoNodoF->izq;
          else if(nuevoNodoF->der!=NULL)
           aux5->der = nuevoNodoF->der;
    }
    free(nuevoNodoF); 
    return 0;

}

int casoTres(){
    nodo* padre= nuevoNodoC;
    nodo *sucesor = nuevoNodoC->der;
    //buscamos el sucesor 
    while(sucesor ->izq!=NULL){
        padre = sucesor;
        sucesor = sucesor->izq;
    }
    nuevoNodoC->codigo= sucesor->codigo;
    if(padre==nuevoNodoC){
        nuevoNodoC->der = sucesor->der; 
    }else{
        padre->izq = sucesor->der;
    }
    free(sucesor);
    return 0; 
}

int casoTresF(){
    nodo* padre= nuevoNodoF;
    nodo *sucesor = nuevoNodoF->der;
    //buscamos el sucesor 
    while(sucesor ->izq!=NULL){
        padre = sucesor;
        sucesor = sucesor->izq;
    }
    nuevoNodoF->codigo= sucesor->codigo;
    if(padre==nuevoNodoF){
        nuevoNodoF->der = sucesor->der; 
    }else{
        padre->izq = sucesor->der;
    }
    free(sucesor);
    return 0; 
}

int eliminarNodo(){
    int buscar, buscar2;
    cout<<"Digite el codigo de el estudiante que desea eliminar"<<endl;
    cin>>buscar;
    buscar2 = buscar; 
    ubicar(raiz, buscar);
    if ((nuevoNodoC->der == NULL)&& (nuevoNodoC->izq == NULL)){
        casoUno();

        }
    else if(((nuevoNodoC->der == NULL)&& (nuevoNodoC->izq != NULL))||((nuevoNodoC->der != NULL)&& (nuevoNodoC->izq == NULL))){
        casoDos();
    }
    else{
        casoTres();
    }


    //creo que se va a eliminar por codigo tambien
    // por fecha 
    ubicarF(raiz2, buscar2);
    if ((nuevoNodoF->der == NULL)&& (nuevoNodoF->izq == NULL)){
        casoUnoF();

        }
        
    else if(((nuevoNodoF->der == NULL)&& (nuevoNodoF->izq != NULL))||((nuevoNodoF->der != NULL)&& (nuevoNodoF->izq == NULL))){
        casoDosF();
    }
    else{
        casoTresF();
    }
    return 0; 
}

int main(){
    int opc;
    do{
        cout<<"1. registrar Estudiante"<<endl;
        cout<<"2. recorrer Arbol"<<endl;
        cout<<"3. eliminar estudiante"<<endl;
        cout<<"4. salir"<<endl; 
        cin>>opc;
        switch (opc)
        {
        case 1:
        

         registrarC();
         
            break;

        case 2: 
         int opc3; 
        cout<<"mostrar arbol por"<<endl;
        cout<<"1.CODIGO"<<endl;
        cout<<"2.FECHA DE NACIMIENTO"<<endl;
        cin>>opc3;
        switch (opc3){
         case 1:
         if (raiz == NULL){
            cout<<"el arbol esta vacio. "<<endl;

         }else {
          int opc2;
           cout<<"En que forma decea realizar el recorrido"<<endl;
           cout<<" 1.preOrden"<<endl;
           cout<<" 2.inOrden"<<endl;
           cout<<" 3.postOrden"<<endl;
           cin>>opc2; 
               switch (opc2)
               {
               case 1: 
               cout<<"PreOrden"<<endl;
               preOrden(raiz);
               break;

               case 2: 
               cout<<"intOrden"<<endl;
               inOrden(raiz);
               break;

               case 3: 
               cout<<"PostOrden"<<endl;
               postOrden(raiz);
               break;
               
               default:cout<<"opcion invalida"<<endl;
                break;
               }
        }
               break;
            
        case 2:
         if (raiz2 == NULL){
            cout<<"el arbol esta vacio. "<<endl;

         }else {
            int opc4; 
            cout<<"En que forma decea realizar el recorrido"<<endl;
           cout<<" 1.preOrden"<<endl;
           cout<<" 2.inOrden"<<endl;
           cout<<" 3.postOrden"<<endl;
           cin>>opc4; 
               switch (opc4)
               {
               case 1: 
               cout<<"PreOrden"<<endl;
               preOrden(raiz2);
               break;

               case 2: 
               cout<<"intOrden"<<endl;
               inOrden(raiz2);
               break;

               case 3: 
               cout<<"PostOrden"<<endl;
               postOrden(raiz2);
               break;
               
               default:
               cout<<"opcion invalida"<<endl;
                break;
               }
         }

            break;
          }

        
    
        break;
        case 3:
        eliminarNodo();
       
          break;

          case 4:
        cout<<"Adioss"<<endl;
       
          break;
        
        }

    }while(opc!=4);
   return 0; 
}

/* INTEGRANTES

Helen Farina Renteria Renteria 
Paola Andrea Sinisterra Mosquera 

*/