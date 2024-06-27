#include "Venta.h"
#include"ArchivoVentas.h"
#include<ctime>

Venta :: Venta(){
    ArchivoVentas _av;

    int cantidad = _av.getCatidadVentas();

    _numeroVenta = cantidad+1;

    time_t t;

    t = time(NULL);

    struct tm *f;
    f = localtime(&t);

    Fecha aux(9,f->tm_mon+1,f->tm_year+1900);

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

    if(_metodoPago == 1){
        _montoTotal = _montoTotal*0.9;
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


void Venta :: registrarVentaEnStock(Venta venta){

    ArchivoProductos _ap;
    int indiceProd;

    Producto auxProd;
    int stockAnterior, stockNuevo;

    for(int i = 0; i < venta._prodDiferentes;i++){
        auxProd = venta._prodsVendidos[i];

        stockAnterior = auxProd.getStock();
        stockNuevo = stockAnterior - _cantidades[i];

        auxProd.setStock(stockNuevo);

        indiceProd = _ap.buscarPorID(auxProd.getId());

        _ap.modificarRegistro(indiceProd, auxProd);
    }
}

Fecha Venta :: getFecha(){
    return _fechaVenta;
}

string Venta :: toCSVString(Venta venta){

    stringstream ss;

    ss << _fechaVenta.toString() << "," <<_numeroVenta << "," << _metodoPago << "," << _montoTotal;

    for (int i = 0; i < venta._prodDiferentes; ++i) {
        ss << _prodsVendidos[i].toCSVString() << "," << _cantidades[i];
    }

    return ss.str();
}

void Venta :: Mostrar(Venta venta){

    for(int i = 0; i < venta._prodDiferentes;i++){

        cout << "Producto: " << venta._prodsVendidos[i].getTipo() << "                   Cantidad: " << venta._cantidades[i] << endl;
        cout << "Marca: " << venta._prodsVendidos[i].getMarca() << endl;
        cout << "Precio: " << venta._prodsVendidos[i].getPrecio() << " $" << endl;
        cout << endl;
    }
    cout << "Total: " << venta._montoTotal << " $" << endl << endl;
}


