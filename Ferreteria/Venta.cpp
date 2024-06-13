#include "Venta.h"


Venta :: Venta(){
    int cantidad = _av.getCatidadVentas();

    _numeroVenta = cantidad+1;

    // agarrar la Fecha del sistema y usar el constructor de aca abajo:

    Fecha aux(xxxx,xxxx,xxxx);

    _fechaVenta = aux;

}

void Venta::agregarProductos(Producto prod, int cantidad, int pos){

    _prodsVendidos[pos] = prod;
    _cantidades[pos] = cantidad;
    
}

void Venta::setProdDiferentes(int cant){
    _prodDiferentes = cant;
}


void Venta::setMontoTotal(){
    int precioProdSeleccion;

    for(int i = 0; i < _prodDiferentes; i++){
        precioProdSeleccion = _prodsVendidos[i].getPrecio()*_cantidades[i];

        _montoTotal += precioProdSeleccion;
    }

}

void Venta::setMetodoPago(int mp){
    _metodoPago = mp;
}

int Venta ::getMetodoPago(){
    return _metodoPago;
}

int Venta::getNroventa(){
    return _numeroVenta;
}

void Venta :: Mostrar(){

}


