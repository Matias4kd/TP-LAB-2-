#include "ReportesManager.h"
#include<iostream>
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

            system("pause");
            break;

        case 2:

            system("pause");
            break;

        case 3:

            system("pause");
            break;

        case 4:

            system("pause");
            break;

        }
    }
    while(option != 0);
}
