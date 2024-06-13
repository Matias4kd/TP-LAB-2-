#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "Producto.h"
#include"Fecha.h"
#include"ArchivoVentas.h"

class Venta{

    private:
        int _numeroVenta;
        Fecha _fechaVenta;
        Producto _prodsVendidos[5];
        int _cantidades[5];
        int _metodoPago;
        float _montoTotal;
        int _prodDiferentes;
        ArchivoVentas _av;


    public:
        Venta();
        void agregarProductos(Producto prod, int cantidad, int posicion);

        void setProdDiferentes(int cant);
        void setMontoTotal();
        void setMetodoPago(int mp);

        int getMetodoPago();
        int getNroventa();

        void Mostrar();


};


#endif // VENTA_H_INCLUDED
