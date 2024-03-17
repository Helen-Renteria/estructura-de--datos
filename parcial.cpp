#include <iostream>
#include <malloc.h>

using namespace std;

struct Producto {
    int id;
    char nombre[50];
    float cantidad;
    float precio;
};

struct nodo
{
  Producto producto;
  nodo* siguiente;
};

nodo* a=NULL;
nodo* b=NULL;

int registar(){
    nodo* cabeza=(nodo*)malloc(sizeof(nodo));

    cout<<"\nIngrese el ID del producto a registrar: ";
    cin>>cabeza->producto.id;

    cout<<"Ingrese el nombre del producto: ";
    cin>>cabeza->producto.nombre;

    cout<<"Ingrese la cantidad: ";
    cin>>cabeza->producto.cantidad;

    cout<<"Ingrese el precio por unidad del producto: ";
    cin>>cabeza->producto.precio;

    cabeza->siguiente=NULL;

    if (b==NULL)
    {
        a=b=cabeza;
    }else{
        b->siguiente=cabeza;
        b=cabeza;
    }
    
    
cout<<"El producto se registro exitosamente.\n";

return 0;
}

int mostrar(){
    nodo* produc=a;

    if(produc==NULL){
        cout<<"\nNo hay inventario.\n";
    
    }

    cout<<"\n----------BIENVENIDO AL INVENTARIO----------\n";
    while (produc!=NULL)
    {
        cout<<"ID: "<<produc->producto.id<<", Nombre: "<<produc->producto.nombre<<", Cantida: "<<produc->producto.cantidad<<", Precio por unidad del producto: "<<produc->producto.precio<< endl;
        produc=produc->siguiente;
    }
     return 0;
}

int buscarPro(int id){
    nodo* produc=a;
    bool encontrar=false;

    while (produc!=NULL)
    {
        if (produc->producto.id==id)
        {
            cout<<"Producto encontrado con exito: "<<endl;
            cout<<"ID: "<<produc->producto.id<<", Nombre: "<<produc->producto.nombre<<", Cantidad: "<<produc->producto.cantidad<<", Precio por unidad del producto: "<<produc->producto.precio<< endl;
            encontrar=true;
            break;
        }
        
        produc=produc->siguiente;
    }

    if(!encontrar){
        cout<<"PRODUCTO NO ENCONTRADO. :(";
    }
     return 0;
    
}

int eliminarPro(int id){
    nodo* produc=a;
    nodo* anterior=NULL;
    bool encontrar=false;

    while (produc!=NULL)
    {
        if(produc->producto.id==id){
            if(produc==a){
                a=produc->siguiente;
            }else{
                anterior->siguiente=produc->siguiente;
            }

            if (produc==b)
            {
                b=anterior;
            }

           free(produc);
           cout<<"¡PRODUCTO ELIMINADO EXITOSAMENTE :)!";
           encontrar=true;
           break;
            
        }
        anterior=produc;
        produc=produc->siguiente;
        
    }
    if (!encontrar)
        {
            cout<<"EL PRODUCTO A ELIMINAR NO SE ENCUENTRA REGISTRADO. :("<<endl;
        }
         return 0;
    

}

int calcularValorInventario(){
    nodo* produc=a;
    double total=0;

    while (produc!=NULL)
    {
      total+=produc->producto.cantidad * produc->producto.precio;
      produc=produc->siguiente;  
    }

    cout<<"El valor total del inventario es: "<<total<<endl;
     return 0;
}


int calcularPromedioPrecios(){
    nodo* produc=a;
    double totalPrecio=0;
    double totalCantidad=0;
    double promedio=0;

    while (produc!=NULL)
    {
        totalPrecio+=produc->producto.precio;
        totalCantidad+=produc->producto.cantidad;
        produc=produc->siguiente;
    }

    promedio=totalPrecio/totalCantidad;
    cout<<"Precio promedio por unidad: "<<promedio<<endl;
     return 0;
}

int vender(){
    float idVenta, cantidadVenta;
    nodo* produc=a;
    bool encontrar=false;

    cout<<"Ingrese el ID del producto a comprar: ";
    cin>>idVenta;

    cout<<"Ingrese la cantidad que quiere comprar: ";
    cin>>cantidadVenta;

    while (produc!=NULL)
    {
        if(produc->producto.id==idVenta){
            if (produc->producto.cantidad>=cantidadVenta)
            {
                float totalVenta=cantidadVenta*produc->producto.precio;
                produc->producto.cantidad-=cantidadVenta;;
                cout<<"Venta realizada. Su total a pagar es: "<<totalVenta<<endl;
            }else{
                cout<<"No hay suficientes unidades disponibles. :(";
            }
            encontrar=true;
            break;
            
        }
        produc=produc->siguiente;
    }

    if (!encontrar)
    {
        cout<<"El producto no se encuentra disponible para la venta. :(";
    }
     return 0;
    
    }

    int main(){
        int opc=0;

        do{
        cout << "\nOpciones:\n";
        cout << "1. Registrar Producto\n";
        cout << "2. Mostrar Inventario\n";
        cout << "3. Buscar Producto por ID\n";
        cout << "4. Eliminar Producto\n";
        cout << "5. Calcular Valor Total del Inventario\n";
        cout << "6. Calcular Promedio de Precios\n";
        cout << "7. Vender Producto\n";
        cout << "8. Salir\n";
        cout << "Ingrese su opcion: ";

        cin >> opc;

        switch (opc)
        {
        case 1:
            registar();
            break;
        case 2:
            mostrar();
            break;
        case 3:
             int buscar;
             cout<<"Ingrese el ID del producto que busca: ";
             cin>>buscar;
             buscarPro(buscar);
             break;
        case 4:
            int eliminar;
            cout<<"Ingrese el ID del producto que quiere eliminar: ";
            cin>>eliminar;
            eliminarPro(eliminar);
            break;
        case 5:
            calcularValorInventario();
            break;
        case 6:
           calcularPromedioPrecios();
           break;
        case 7:
           vender();
           break;
        default:
           cout<<"Opcion no valida. Por favor sea tan amable de volver a intentarlo."<<endl;
            
        }

        }while (opc!=8);
       
        
        
        
    }