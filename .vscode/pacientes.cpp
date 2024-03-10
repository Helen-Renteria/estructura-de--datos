#include<iostream>
#include<malloc.h>
using namespace std;

struct pacientes
{
    int valor = 0;
    char nombre[30];
    pacientes *siguiente;
   
};


pacientes *cabeza, *auxiliar1, *auxiliar2;
   


int registro(){
    if(cabeza==NULL){
        cabeza=(struct pacientes *)malloc(sizeof(struct pacientes));
        cout<<"Ingrese el nombre del paciente: ";
        cin>>cabeza->nombre;
        cout<<"Ingrese el documento del paciente: ";
        cin>>cabeza->valor;
        cabeza->siguiente=NULL;
    }else{
         auxiliar1=(struct pacientes *)malloc(sizeof(struct pacientes));
         cout<<"Ingrese el nombre del paciente: ";
         cin>>auxiliar1->nombre;
         cout<<"Ingrese el documento del paciente: ";
        cin>>auxiliar1->valor;
         auxiliar1->siguiente=NULL;
         auxiliar2=cabeza;
         while(auxiliar2->siguiente!=NULL)
            auxiliar2=auxiliar2->siguiente;
         auxiliar2->siguiente=auxiliar1;
         auxiliar2=auxiliar1=NULL;
         free(auxiliar1);
         free(auxiliar2);
}
return 0;
 
}

int mostrar(){

    for (auxiliar1=cabeza;auxiliar1!=NULL;auxiliar1=auxiliar1->siguiente){
        cout<<"NOMBRE DEL PACIENTE: "<<auxiliar1->nombre<<endl;
        cout<<"DOCUMENTO DEL PACIENTE: "<<auxiliar1->valor<<endl;
        
    }
    
        return 0;
    }

int main(){
string nombre;

        int opcion=0;


        do{
            cout<<"MENU"<<endl;
            cout<<"1. REGISTRAR PACIENTE"<<endl;
            cout<<"2. VER PACIENTES"<<endl;
            cout<<"3. SALIR DEL MENU"<<endl;
            cin>>opcion;

            switch(opcion){
                case 1: registro();break;
                case 2: mostrar();break;
                case 3: cout<<"ADIOS";break;
                default:cout<<"Opcion invalida";break;
            }
            
        }while (opcion!=3);
        
            
        
    }