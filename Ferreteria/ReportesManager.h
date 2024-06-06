#ifndef REPORTESMANAGER_H_INCLUDED
#define REPORTESMANAGER_H_INCLUDED

#include "Producto.h"
#include "ArchivoProductos.h"

class ReportesManager{

    private:
        void generarReporteSenamal();
        void generarReporteMensual();
        void generarReporteAnual();
        void generarReporteHistorico();

    public:

        void Menu();

};

#endif // REPORTESMANAGER_H_INCLUDED
