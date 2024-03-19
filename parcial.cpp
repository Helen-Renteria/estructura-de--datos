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
    int total=0;

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
    int totalPrecio=0;
    int totalCantidad=0;
    int promedio=0;

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
    int idVenta, cantidadVenta;
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
                encontrar=true;

                cout << "*Informacion del producto:*" << endl;
      cout << "ID: " << produc->producto.id << endl;
      cout << "Nombre: " << produc->producto.nombre << endl;
      cout << "Cantidad disponible: " << produc->producto.cantidad << endl;
      cout << "Precio por unidad: " << produc->producto.precio << endl;

                int totalVenta=cantidadVenta*produc->producto.precio;
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
       
        return 0;
    }