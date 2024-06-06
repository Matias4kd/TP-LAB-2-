#ifndef MANAGERARCHIVOS_H_INCLUDED
#define MANAGERARCHIVOS_H_INCLUDED
#include "Producto.h"
#include<iostream>
using namespace std;



class ArchivoProductos{
    
    private:

    public:
        int getNewId();
        int buscarPorID(int id);
        int getCantidadRegistros();
        Producto leer(int index);
        bool modificarRegistro(int index, Producto prod);
        bool guardar(Producto prod);
        void leerTodos(Producto registros[], int cantidad);
};

#endif // MANAGERARCHIVOS_H_INCLUDED
