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
            realizarVenta();
            system("pause");
            break;

        case 2:
            listarProductos();
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