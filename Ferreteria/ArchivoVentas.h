#pragma once
#include "Producto.h"
#include"Venta.h"
#include<iostream>

using namespace std;

class ArchivoVentas{
    private:

    public:
        void getNroVentaNueva();
        void leerVentas(Venta ventas[], int cantidad);
        bool guardarVenta(Venta venta);
        int getCatidadVentas();
};











