#include "ReportesManager.h"
#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;


void ReportesManager :: Menu(){
    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU REPORTES ------- " << endl;
        cout << "1- VENTAS SEMANALES" << endl;
        cout << "2- VENTAS MENSUALES" << endl;
        cout << "3- VENTAS ANUALES" << endl;
        cout << "4- HISTORICO VENTAS TOTALES" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            generarReporteSemanal();
            system("pause");
            break;

        case 2:
            generarReporteMensual();
            system("pause");
            break;

        case 3:
            generarReporteAnual();
            system("pause");
            break;

        case 4:
            generarReporteHistorico();
            system("pause");
            break;

        }
    }
    while(option != 0);
}

void ReportesManager :: generarReporteHistorico(){
    
    Venta *ventas;

    int cant;

    cant = _av.getCatidadVentas();

    ventas = new Venta[cant];

    _av.leerVentas(ventas,cant);

    ofstream archivoSalida("Historico ventas.csv");

    if (archivoSalida.is_open()) {
            
        for(int i = 0; i < cant; i ++){
            archivoSalida << ventas[i].toCSVString(ventas[i]) << "\n";
        }
        cout << "Reporte generado con exito!" << endl;

        archivoSalida.close();
    } else {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    delete[] ventas;
     
}

void ReportesManager :: generarReporteAnual(){
    
    Venta *ventas;

    int cant;

    cant = _av.getCatidadVentas();
    ventas = new Venta[cant];
    _av.leerVentas(ventas,cant);

    int anioSeleccionado;

    cout << "De que anio necesita reporte (AAAA): ";
    cin >> anioSeleccionado;

    ofstream archivoSalida("Reporte Anual ventas.csv");

    if (archivoSalida.is_open()) {
            
        for(int i = 0; i < cant; i ++){

            if(ventas[i].getFecha().getAnio() == anioSeleccionado){
                archivoSalida << ventas[i].toCSVString(ventas[i]) << "\n";
            }
        }
        cout << endl << "Reporte generado con exito!" << endl << endl;

        archivoSalida.close();
    } else {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    delete[] ventas;
}

void ReportesManager :: generarReporteMensual(){
    Venta *ventas;

    int cant;

    cant = _av.getCatidadVentas();
    ventas = new Venta[cant];
    _av.leerVentas(ventas,cant);

    int mesSeleccionado, anioSeleccionado;

    cout << "Seleccione a que anio corresponde el mes a consultar(AAAA): ";
    cin >> anioSeleccionado;
    cout << "De que mes necesita reporte: ";
    cin >> mesSeleccionado;

    ofstream archivoSalida("Reporte mensual ventas.csv");

    if (archivoSalida.is_open()) {
            
        for(int i = 0; i < cant; i ++){

            if(ventas[i].getFecha().getAnio() == anioSeleccionado && ventas[i].getFecha().getMes() == mesSeleccionado){
                archivoSalida << ventas[i].toCSVString(ventas[i]) << "\n";
            }
        }
        cout << endl << "Reporte generado con exito!" << endl << endl;

        archivoSalida.close();
    } else {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    delete[] ventas;
}

void ReportesManager :: generarReporteSemanal(){
    Venta *ventas;

    int cant;

    cant = _av.getCatidadVentas();
    ventas = new Venta[cant];
    _av.leerVentas(ventas,cant);

    int mesSeleccionado, anioSeleccionado, inicioSemana, finSemana;

    cout << "Seleccione a que anio corresponde el mes a consultar(AAAA): ";
    cin >> anioSeleccionado;
    cout << "De que mes corresponde la semana a consultar: ";
    cin >> mesSeleccionado;
    cout << "Indique con que numero de dia comienza la semana a consultar: ";
    cin >> inicioSemana;


    ofstream archivoSalida("Reporte semanal ventas.csv");

    if (archivoSalida.is_open()) {
            
        for(int i = 0; i < cant; i ++){

            if(ventas[i].getFecha().getAnio() == anioSeleccionado && ventas[i].getFecha().getMes() == mesSeleccionado && (ventas[i].getFecha().getDia() >= inicioSemana && ventas[i].getFecha().getDia() < inicioSemana +7)){
                archivoSalida << ventas[i].toCSVString(ventas[i]) << "\n";
            }
        }
        cout << endl << "Reporte generado con exito!" << endl << endl;

        archivoSalida.close();
    } else {
        cerr << "Error al abrir el archivo de salida." << endl;
    }

    delete[] ventas;
}