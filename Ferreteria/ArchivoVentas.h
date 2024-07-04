#ifndef ARCHIVOVENTA_H_INCLUDED
#define ARCHIVOVENTA_H_INCLUDED
#include "Producto.h"
#include"Venta.h"
#include<iostream>

using namespace std;

class ArchivoVentas{
    private:

    public:
        void leerVentas(Venta ventas[], int cantidad);
        bool guardarVenta(Venta venta);
        int getCatidadVentas();
};

#endif // ARCHIVOVENTA_H_INCLUDED









