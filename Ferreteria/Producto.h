#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include <string>
#include <cstring>
using namespace std;

class Producto{

    private:

        int _id;
        char _marca[50];
        float _precio;
        char _tipo[50];
        int _stock;
        char _proveedor[50];
        bool _eliminado;

    public:

        Producto(int id,string marca, float precio, string tipo, int stock, string proveedor, bool eliminado);
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
        string toCSVString();

};

#endif // PRODUCTO_H_INCLUDED