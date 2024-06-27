#ifndef REPORTESMANAGER_H_INCLUDED
#define REPORTESMANAGER_H_INCLUDED

#include "Venta.h"
#include "ArchivoVentas.h"

class ReportesManager{

    private:
        void generarReporteSemanal();
        void generarReporteMensual();
        void generarReporteAnual();
        void generarReporteHistorico();
        
        ArchivoVentas _av;

    public:

        void Menu();

};

#endif // REPORTESMANAGER_H_INCLUDED
