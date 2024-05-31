#include "Producto.h"
#include "ArchivoProductos.h"
#include<cstring>
using namespace std;

Producto :: Producto(int id,string marca, float precio, string tipo, int stock, string proveedor, bool eliminado)
{
    setId(id);
    setMarca(marca);
    setPrecio(precio);
    setTipo(tipo);
    setStock(stock);
    setProveedor(proveedor);
    setEliminado(eliminado);
}

Producto::Producto(){
    _id = 0;
    setMarca("");
    setPrecio(0);
    setTipo("");
    setStock(0);
    setProveedor("");
    setEliminado(false);
}

#pragma region Setters

void Producto :: setId(int id)
{
    _id = id;
}

void Producto :: setMarca(string marca)
{
    if(marca.size()<= 50){
        strcpy(_marca, marca.c_str());
    }
}

void Producto :: setPrecio(float precio)
{
    _precio = precio;
}

void Producto :: setTipo(string tipo)
{
    if(tipo.size()<= 50){
        strcpy(_tipo, tipo.c_str());
    }
}

void Producto :: setStock(int stock)
{
    _stock = stock;
}

void Producto :: setProveedor(string proveedor)
{
    if(proveedor.size()<= 50){
        strcpy(_proveedor, proveedor.c_str());
    }
}

void Producto :: setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}

#pragma endregion

#pragma region Geters

int Producto :: getId()
{
    return _id;
}

string Producto :: getMarca()
{
    return _marca;
}

float Producto :: getPrecio()
{
    return _precio;
}

string Producto :: getTipo()
{
    return _tipo;
}

int Producto :: getStock()
{
    return _stock;
}

string Producto ::getProveedor()
{
    return _proveedor;
}

bool Producto :: getEliminado()
{
    return _eliminado;
}

#pragma endregion
