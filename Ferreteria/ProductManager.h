#ifndef PRODUCTMANAGER_H_INCLUDED
#define PRODUCTMANAGER_H_INCLUDED

#include "Producto.h"
#include "ArchivoProductos.h"
#include "ArchivoVentas.h"

class ProductManager{

    private:
        void realizarVenta();
        void menuListados();
        void listarTodosProductos();
        void listarPorTipo();
        void listarPorMarca();
        void listarPorProveedor();
        void verificarStock();
        void agregarProducto();
        void modificarProducto();
        void eliminarProducto();
        void mostrarProducto(Producto registro);

        ArchivoProductos _ap;
        ArchivoVentas _av;




    public:

        void Menu();
};

#endif // PRODUCTMANAGER_H_INCLUDED
