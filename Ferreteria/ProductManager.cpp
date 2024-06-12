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
        cout << endl;

        switch(option)
        {
        case 1:
//            realizarVenta();
            system("pause");
            break;

        case 2:
            menuListados();
            system("pause");
            break;

        case 3:
            verificarStock();
            system("pause");
            break;

        case 4:
            agregarProducto();
            system("pause");
            break;

        case 5:
            modificarProducto();
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

void ProductManager::menuListados(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU PRODUCTOS ------- " << endl;
        cout << "1- LISTAR TODOS " << endl;
        cout << "2- LISTAR POR TIPO" << endl;
        cout << "3- LISTAR POR MARCA" << endl;
        cout << "4- LISTAR POR PROVEEDOR" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl << endl;
        cout << "Opcion: ";
        cin >> option;
        cout << endl;

        switch(option)
        {
        case 1:
            listarTodosProductos();
            system("pause");
            break;

        case 2:
            listarPorTipo();
            system("pause");
            break;

        case 3:
            listarPorMarca();
            system("pause");
            break;
        
        case 4:
            listarPorProveedor();
            system("pause");
            break;
        }
    }
    while(option != 0);
}

void ProductManager::listarTodosProductos(){

    int cantidad = _ap.getCantidadRegistros();
    Producto *productos;

    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _ap.leerTodos(productos, cantidad);

    cout << "Listado de productos: " << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(!(productos[i].getEliminado()))
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] productos;
}

void ProductManager::listarPorTipo(){

    int cantidad = _ap.getCantidadRegistros();
    Producto *productos;

    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _ap.leerTodos(productos, cantidad);

    string tipo;


    cout << "SELECCIONO LISTADO POR TIPO, INDIQUE QUE TIPO DE PRODUCTOS DESEA LISTAR" << endl;
    cout << "TIPO: ";
    cin.ignore();
    getline(cin, tipo);
 

    cout << "Listado de productos por tipo: " << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(!(productos[i].getEliminado()) && productos[i].getTipo() == tipo)
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] productos;
}

void ProductManager::listarPorMarca(){

    int cantidad = _ap.getCantidadRegistros();
    Producto *productos;

    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _ap.leerTodos(productos, cantidad);

    string marca;

    cout << "SELECCIONO LISTADO POR MARCA, INDIQUE QUE TIPO DE PRODUCTOS DESEA LISTAR" << endl;
    cout << "MARCA: ";
    cin.ignore();
    getline(cin, marca);


    cout << "Listado de productos por marca: " << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(!(productos[i].getEliminado()) && productos[i].getMarca() == marca)
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] productos;
}

void ProductManager::listarPorProveedor(){

    int cantidad = _ap.getCantidadRegistros();
    Producto *productos;

    productos = new Producto[cantidad];

    if(productos == nullptr)
    {
        cout << "No se pudo pedir memoria... " << endl;
        return;
    }

    _ap.leerTodos(productos, cantidad);

    string proveedor;

    cout << "SELECCIONO LISTADO POR PROVEEDOR, INDIQUE QUE TIPO DE PRODUCTOS DESEA LISTAR" << endl;
    cout << "PROVEEDOR: ";
    cin.ignore();
    getline(cin, proveedor);

    cout << "Listado de productos por proveedor: " << endl;
    for(int i=0; i<cantidad; i++)
    {
        if(!(productos[i].getEliminado()) && productos[i].getProveedor() == proveedor)
        {
            cout << "--------------------------" << endl;
            mostrarProducto(productos[i]);
            cout << "--------------------------" << endl;
        }
    }

    delete[] productos;
}

void ProductManager::verificarStock(){
    int idProducto, index;
    Producto producto;

    cout << "Ingrese id del producto a verificar el stock: ";
    cin >> idProducto;

    index = _ap.buscarPorID(idProducto);

    if(index != -1){
        producto = _ap.leer(index);

        cout << endl;
        cout << "Producto " << producto.getTipo() << endl;
        cout << "Marca " << producto.getMarca() << endl;
        cout << "Stock restante: " << producto.getStock() << endl;

        if(producto.getStock() <= 30){
            cout << endl;
            cout << "CONTACTAR AL PROVEEDOR PARA REPOSICION DE STOCK." << endl;
        }

    }

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
        cout << "Precio: " << registro.getPrecio() << endl;
        cout << "Stock: " << registro.getStock() << endl;
        cout << "Proveedor: " << registro.getProveedor() << endl;
    }
}

void ProductManager::modificarProducto(){
    int idProducto, index;
    Producto producto;
    bool modificar;

    int opcion;


    cout << "Ingrese id del producto a modificar: ";
    cin >> idProducto;

    index = _ap.buscarPorID(idProducto);

    if(index != -1){
        producto = _ap.leer(index);

        cout << endl;
        mostrarProducto(producto);

        cout << endl;
        cout << "Seleccione que desea modificar:" << endl;
        cout << "-----------------------------" << endl;
        cout << "1- PRECIO" << endl;
        cout << "2- STOCK" << endl;
        cout << "3- PROVEEDOR" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- CANCELAR" << endl;
        cout << endl;

        cout << "Opcion: ";
        cin >> opcion;

    if(opcion != 0){
            
            switch (opcion)
            {
            case 1:
                float precio;
                cout << "Ingrese el precio:";
                cin >> precio;
                producto.setPrecio(precio); 
                break;
            
            case 2:
                int stock;
                cout << "Ingrese el stock: ";
                cin >> stock;
                producto.setStock(stock);
                break;

            case 3:
                string proveedor;
                cin.ignore();
                cout << "Ingrese el proveedor: ";
                getline(cin,proveedor);
                producto.setProveedor(proveedor);
                break;            
            }

            cout << endl;
            mostrarProducto(producto);
            cout << endl;

            cout << "Esta segudo de que quiere modificarlo? 1-Si 0-No: ";
            cin >> modificar;

        }else{
            return;
        }

        if(modificar){

            if(_ap.modificarRegistro(index, producto))
            {
                cout << "Se modifico con exito!" << endl;
            }
            else
            {
                cout << "No se pudo modificar el producto!" << endl;
            }
        }
        else{
            cout << "El producto no fue modificado!" << endl;

        }

    }
    else{
        cout << "No se encuentra ese producto!" << endl;
    }
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