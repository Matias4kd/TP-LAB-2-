#ifndef APPMANAGER_H_INCLUDED
#define APPMANAGER_H_INCLUDED
#include "ProductManager.h"
#include "ArchivoProductos.h"

class AppManager{

    private:

        ProductManager _pm;
        ArchivoProductos _ap;

    public:

        void Menu();
};

#endif // APPMANAGER_H_INCLUDED
