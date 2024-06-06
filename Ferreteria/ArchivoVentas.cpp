#include "ArchivoVentas.h"


void ArchivoVentas :: leerVentas(Venta ventas[], int cantidad){
    
    FILE *p;

    p = fopen("ventas.dat", "rb");
   
    if(p == nullptr){
       return;
    }
   
    fread(ventas, sizeof(Venta), cantidad, p);
   
    fclose(p);
}

bool ArchivoVentas :: guardarVenta(Venta venta){
    bool result;
    FILE *p;

    p = fopen("ventas.dat", "ab");

    if(p == nullptr){

        return false;
    }

   result = fwrite(&venta, sizeof (Venta), 1, p);

   fclose(p);

   return result;
}

int ArchivoVentas :: getCatidadVentas(){
    FILE *p;
    int tam;

    p = fopen("ventas.dat", "rb");

    if(p == nullptr){
        return 0;
    }

    fseek(p, 0, SEEK_END);

    tam = ftell(p) / sizeof (Venta);

    fclose(p);

    return tam;
}