#include <iostream>
#include <cstring>

using namespace std;

#include "fecha.h"
#include "proveedor.h"
#include "producto.h"
#include "compra.h"
#include "submenuProveedores.h"

int main() {
    int opcion;
    cout << "1: Proveedores" << endl;
    cout << "2: Compras" << endl;
    cout << "3: Productos" << endl;
    cout << "4: Configuracion" << endl;
    cout << "0: Salir del programa" << endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    while (opcion!=0)
    {
        system("cls");

        switch (opcion) {
        case 1:
            submenuProveedores();
        }

        system("cls");

        cout << "1: Proveedores" << endl;
        cout << "2: Compras" << endl;
        cout << "3: Productos" << endl;
        cout << "4: Configuracion" << endl;
        cout << "0: Salir del programa" << endl;
        cout << "Ingrese opcion:" << endl;
        cin >> opcion;
    }

    return 0;
}
