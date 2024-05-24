#ifndef PRODUCTMANAGER_H_INCLUDED
#define PRODUCTMANAGER_H_INCLUDED

#include "Producto.h"
#include "ArchivoProductos.h"

class ProductManager{

    private:
        void realizarVenta();
        void listarProductos();
        void verificarStock();
        void agregarProducto();
        void modificarProducto();
        void eliminarProducto();

    public:

        void Menu();
};

#endif // PRODUCTMANAGER_H_INCLUDED
