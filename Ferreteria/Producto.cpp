#include "Producto.h"
#include "ArchivoProductos.h"

Producto :: Producto()
{

}

#pragma region Setters

void Producto :: setId(int id)
{
    _id = id;
}

void Producto :: setMarca(string marca) 
{
    _marca = marca;
}

void Producto :: setPrecio(float precio) 
{
    _precio = precio;
}

void Producto :: setTipo(string tipo) 
{
    _tipo = tipo;
}

void Producto :: setStock(int stock) 
{
    _stock = stock;
}

void Producto :: setProveedor(string proveedor)
{
    _proveedor = proveedor;
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
