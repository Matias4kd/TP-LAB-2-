#include"ArchivoProductos.h"

int ArchivoProductos::getNewId(){
    int cantidad = getCantidadRegistros();

    if(cantidad>=0){

        return cantidad+1;
    }
    else{
        cout << "Ocurrio un error al crear el ID del Producto;";
        return -1;
    }
}

bool ArchivoProductos::guardar(Producto registro){

    bool result;
    FILE *p;

    p = fopen("productos.dat", "ab");

    if(p == nullptr){

        return false;
    }

   result = fwrite(&registro, sizeof (Producto), 1, p);

   fclose(p);

   return result;
}

int ArchivoProductos::getCantidadRegistros(){
    FILE *p;
    int tam;

    p = fopen("productos.dat", "rb");

    if(p == nullptr){
        return 0;
    }

    fseek(p, 0, SEEK_END);

    tam = ftell(p) / sizeof (Producto);

    fclose(p);

    return tam;
}

bool ArchivoProductos:: modificarRegistro(int index, Producto prod){
    bool result;
    FILE *p;

    p = fopen("productos.dat", "rb+");

    if(p == nullptr){

       return false;
    }

    fseek(p, sizeof(Producto) * index, SEEK_SET);

    result = fwrite(&prod, sizeof (Producto), 1, p);

    fclose(p);

    return result;
}

int ArchivoProductos :: buscarPorID(int id){

    Producto reg;
    int pos = 0;
    FILE * p;

    p = fopen("productos.dat", "rb");
    if(p == nullptr){
        return -1;
    }

    while(fread(&reg, sizeof(Producto), 1, p)){
        if(reg.getId() == id){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

Producto ArchivoProductos:: leer(int index){
    bool result;
    Producto reg;
    FILE *pFile;

    pFile = fopen("productos.dat", "rb");

    if(pFile == nullptr){
        return reg;
    }

    fseek(pFile, index * sizeof (Producto), SEEK_SET);

    fread(&reg, sizeof(Producto), 1, pFile);

    fclose(pFile);

    return reg;
}

void ArchivoProductos :: leerTodos(Producto registros[], int cantidad){
    FILE *p;

    p = fopen("productos.dat", "rb");
   
    if(p == nullptr){
       return;
    }
   
    fread(registros, sizeof(Producto), cantidad, p);
   
    fclose(p);
}
