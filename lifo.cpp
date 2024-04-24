
/**
 * Tengo un parqueadero de callejon con ocupacion para Motos y Carros.
 *  Los cuales se parquean en sistema LIFO. Los carros tiene un valor de parqueo
 *  de 1.000 y motos 500, pero al retirarlos cada movimiento adicional de vehiculos cuesta 100 
 * para carro  y 50 para moto. Calcular el valor devegando en x momento del dia.
 * 
*/
#include<iostream>
#include<malloc.h>
using namespace std;

struct vehiculos{
    char propietario [5];
    int placa=0;
    vehiculos *sig;
    
}; 

vehiculos *aux, *top, *aux2, *top2;
 int Ndecarros=0, Ndemotos=0, Ndevehiculos=0,CM=0,CC=0;
int registrar(){
    
   int  opc=0;
   cout<<"ingrese el tipo de vehiculo que desea registrar"<<endl<<"1. carro"<<endl<<"2.moto"<<endl; 
   cin>>opc;

if(opc==1){
     aux = (struct vehiculos *) malloc(sizeof(struct vehiculos));
    cout<<"ingrese la placa del vehiculo"<<endl;
    cin>>aux->placa;
    cout<<"ingrese la iniciales del propietario"<<endl; 
    cin>>aux->propietario;


      if(top==NULL){
        top = aux;
        top->sig = NULL;
    } else {
        aux->sig = top;
        top = aux;
       
    }
     Ndecarros++;
    aux = NULL;
    free(aux);
    

}

if(opc==2){
    aux2 = (struct vehiculos *) malloc(sizeof(struct vehiculos));
    cout<<"ingrese la placa del vehiculo"<<endl;
    cin>>aux2->placa;
    cout<<"ingrese la iniciales del propietario"<<endl; 
    cin>>aux2->propietario;

    if(top2==NULL){
        top2=aux2;
        top2->sig=NULL; 
    }else{
        aux2->sig=top2;
        top2=aux2;
    }
    Ndemotos++;


}

 Ndevehiculos=Ndecarros+Ndemotos;
    cout<<"el numero de vehiculos es"<<Ndevehiculos<<endl; 
 return 0;   
}

int mostrar(){
    cout<<" ***VEHICULOS PARQUEADOS*** "<<endl;
    aux=top;
    cout<<"CARROS"<<endl;
    while(aux!=NULL){
       
        cout<<aux->placa<<endl;
        aux=aux->sig;


    }

    aux2=top2;
    cout<<"MOTOS"<<endl;
    while(aux2!=NULL){
       
        cout<<aux2->placa<<endl;
        aux2=aux2->sig;


    }

return 0;
}

int eliminar(){
    int opc=0;
    cout<<"ingrese el tipo d vehiculo que desea retirar"<<endl;
    cout<<"1. CARROS"<<"2. MOTOS"<<endl;
    cin>>opc;

    if(opc==1){
        int placaEliminar=0;
        cout<<"ingrese la placa del carro que desea retirar"<<endl;
        cin>>placaEliminar;

        vehiculos *anterior = NULL;
        aux = top;
        while(aux != NULL && aux->placa != placaEliminar){
            anterior = aux;
            aux = aux->sig;
            //contador para carros 
            CC++;

        }
        cout<<"se movieron"<<CC<<endl;
        if(aux == NULL){
            cout << "No se encontró ningún carro con esa placa." << endl;
            return 0;
        }
        if(anterior == NULL){
            top = aux->sig;
        } else {
            anterior->sig = aux->sig;
        }
        free(aux);
        cout << "El carro con placa " << placaEliminar << " ha sido retirado correctamente." << endl;  
       
    }

    
    if(opc==2){
         int placaEliminar=0;
        cout<<"ingrese la placa de la moto que desea retirar"<<endl;
        cin>>placaEliminar;

        vehiculos *anterior = NULL;
        aux = top;
        while(aux != NULL && aux->placa != placaEliminar){
            anterior = aux;
            aux = aux->sig;
            CM++; //contador para motos
        }
         cout<<"se movieron"<<CC<<endl;
        if(aux == NULL){
            cout << "No se encontró ningúna moto con esa placa." << endl;
            return 0;
        }
        
        if(anterior == NULL){
            top = aux->sig;
        } else {
            anterior->sig = aux->sig;
        }
        free(aux);
        cout << "La moto con la placa " << placaEliminar << " ha sido retirado correctamente." << endl;  
       
    }
    return 0; 



}
int calcular(){
//calculemos el numero de vehiculos 

int totalc=0,totalm=0, totalv=0;

totalc= (Ndecarros*1000)+(CC*100);
totalm=(Ndemotos*500)+(CM*50);
//total de solo parquear motos y carros
totalv= totalc+totalm;




cout<<"--DINERO RECIBIDO EN EL PARQUEADERO--"<<endl;
cout<<"CARROS: $"<<totalc<<endl;
cout<<"MOTOS: $"<<totalm<<endl; 
cout<<"TOTAL: $"<<totalv<<endl; 

return 0;

}




int main(){
    
    int opc=0;
    do{
        cout<<endl<<"BIENVENIDOS AL PARQUEADERO LA ESTRELLA"<<endl;
        cout<<"selecione la accion que decea realizar"<<endl;
        cout<<"1. parquear vehiculo"<<endl;
        cout<<"2. mostrar vehiculos parqueados"<<endl;
        cout<<"3. sacar un vehiculo del parqueadero"<<endl; 
        cout<<"4. dinero del parqueadero"<<endl;
        cout<<"5. salir de programa"<<endl;
        cin>>opc;
        switch (opc){
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: eliminar(); break;
            case 4: calcular();break;
            case 5:
              cout<<"hasta luego... espero que vuelvas";
        }
    } while(opc!=5);

    return 0;



}

