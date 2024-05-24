#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
#include <cstring>
using namespace std;

class Producto{

    private:

        int _id;
        string _marca;
        float _precio;
        string _tipo;
        int _stock;
        string _proveedor;
        bool _eliminado;

    public:

        Producto();

        void setId(int id);
        void setMarca(string marca);
        void setPrecio(float precio);
        void setTipo(string tipo);
        void setStock(int stock);
        void setProveedor(string proveedor);
        void setEliminado(bool eliminado);

        int getId();
        string getMarca();
        float getPrecio();
        string getTipo();
        int getStock();
        string getProveedor();
        bool getEliminado();

};

#endif // PRODUCTO_H_INCLUDED
