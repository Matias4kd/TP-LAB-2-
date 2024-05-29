#include"AppManager.h"
#include <iostream>
using namespace std;


void AppManager::Menu(){

    int option;
    system("cls");
    do
    {
        system("cls");

        cout << "------ MENU PRINCIPAL ------- " << endl;
        cout << "1- PRODUCTOS" << endl;
        cout << "2- REPORTES" << endl;
        cout << "-----------------------------" << endl;
        cout << "0- SALIR" << endl << endl;
        cout << "Opcion: ";
        cin >> option;

        switch(option)
        {
        case 1:
            _pm.Menu();
            system("pause");
            break;

        case 2:
            _rm.Menu();
            system("pause");
            break;

        }

    }
    while(option != 0);



}
