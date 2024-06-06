#ifndef APPMANAGER_H_INCLUDED
#define APPMANAGER_H_INCLUDED
#include "ProductManager.h"
#include "ReportesManager.h"

class AppManager{

    private:
        ProductManager _pm;
        ReportesManager _rm;

    public:

        void Menu();
};

#endif // APPMANAGER_H_INCLUDED
