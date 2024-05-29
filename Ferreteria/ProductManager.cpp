#include <iostream>
#include "ProductManager.h"
#include "Venta.h"
using namespace std;



void ProductManager :: Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU PRODUCTOS ------- " << endl;
        cout << "1- VENDER PRODUCTO " << endl;
        cout << "2- LISTAR PRODUCTOS" << endl;
        cout << "3- VERIFICAR STOCK" << endl;
        cout << "4- AGREGAR PRODUCTO" << endl;
        cout << "5- MODIFICAR PRODUCTO" << endl;
        cout << "6- ELIMINAR PRODUCTO" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
//            realizarVenta();
            system("pause");
            break;

        case 2:
            listarProductos();
            system("pause");
            break;

        case 3:
//            verificarStock();
            system("pause");
            break;

        case 4:
            agregarProducto();
            system("pause");
            break;

        case 5:
//            modificarProducto();
            system("pause");
            break;

        case 6:
            eliminarProducto();
            system("pause");
            break;
        }
    }
    while(option != 0);
}


void ProductManager::realizarVenta(){

}


void ProductManager::listarProductos(){

    int cantidad = _ap.getCantidadRegistros();
    Producto *productos;

    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _ap.leerTodos(productos, cantidad);

    for(int i=0; i<cantidad; i++)
    {
        if(!productos[i].getEliminado())
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] productos;
}


void ProductManager::verificarStock(){

}


void ProductManager::agregarProducto(){

    bool guardado = false;

    int id, stock;
    string marca, tipo, proveedor;
    float precio;
    bool eliminado = false;

    id = _ap.getNewId();

    if(id <0){
        return;
    }

    cout << "ID del producto: " << id << endl;
    cin.ignore();
    cout << "Ingrese el tipo de producto: ";
    getline(cin, tipo);
    cout << "Ingrese la marca del producto: ";
    getline(cin, marca);
    cout << "Ingrese el stock del producto: ";
    cin >> stock;
    cout << "Ingrese el precio del producto: ";
    cin >> precio;
    while(precio < 0){
        cout << "Debe ingresar un precio valido (Mayor a 0)" << endl;
        cout << "Ingrese el precio del producto: ";
        cin >> precio;
    }
    cout << "Ingrese el proveedor:";
    cin.ignore();
    getline(cin, proveedor);


    Producto prod(id,marca,precio,tipo,stock,proveedor,eliminado);

    guardado =_ap.guardar(prod);

    if(guardado){
        cout << "El producto fue creado con exito!" << endl;
    }
    else{
        cout << "No se pudo crear el producto" << endl;
    }

}

void ProductManager :: mostrarProducto(Producto registro){
    
    if(!registro.getEliminado()){
        cout << "ID " << registro.getId() << endl;
        cout << "Producto: " << registro.getTipo() << endl;
        cout << "Marca: " << registro.getMarca() << endl;
        cout << "Precio: " << registro.getPrecio();
        cout << "Stock: " << registro.getStock();
        cout << "Proveedor: " << registro.getProveedor();
    }
}

void ProductManager::modificarProducto(){

}

void ProductManager::eliminarProducto(){
    int idProducto, index;
    Producto producto;
    bool eliminar;

    cout << "Ingrese id del producto a eliminar: ";
    cin >> idProducto;

    index = _ap.buscarPorID(idProducto);

    if(index != -1){
        producto = _ap.leer(index);

        mostrarProducto(producto);

        cout << "Esta segudo de que quiere eliminarlo? 1-Si 0-No: ";
        cin >> eliminar;

        if(eliminar){
            producto.setEliminado(true);

            if(_ap.modificarRegistro(index, producto))
            {
                cout << "Se elimino con exito!" << endl;
            }
            else
            {
                cout << "No se pudo eliminar el producto!" << endl;
            }
        }
        else{
            cout << "El producto no fue eliminado!" << endl;

        }

    }
    else{
        cout << "No se encuentra ese producto!" << endl;
    }
}


