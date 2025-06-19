#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED

#include "archivoProveedores.h"

void submenuProveedores(){
    ArchivoProveedores archivo("proveedores.dat");

    system("cls");
    int opcion;
    cout << "1: Aniadir" << endl;
    cout << "2: Eliminar" << endl;
    cout << "3: Listar proveedores" << endl;
    cout << "4: Consultar proveedor por cuit" << endl;
    cout << "0: Volver al menu principal" << endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    while (opcion!=0)
    {
        system("cls");
        switch(opcion) {
        case 1:
            {
                Proveedor reg;
                reg.ingresarDatos();

                if (archivo.agregarRegistro(reg))
                    cout << "Registro aniadido correctamente.";
                else
                    cout << "Hubo un error al aniadir el registro.";

                system("pause");
            }
            break;
        case 2:
            {
                int cuit;
                cout << "Ingrese cuit del proveedor a eliminar: " << endl;
                cin >> cuit;

                archivo.eliminarRegistro(archivo.posicionRegistro(cuit));
            }
            break;
        case 3:
            {
                cout << "Registros de proveedores: " << endl << endl;
                for (int i = 0; i < archivo.contarRegistros(); i++) {
                    archivo.leerRegistro(i).mostrar();
                    cout << endl;
                }

                system("pause");
            }
            break;
        case 4:
            {
                int cuit;
                cout << "Ingrese cuit del proveedor a consultar: " << endl;
                cin >> cuit;

                system("cls");

                bool encontrado = false;

                for (int i = 0; i < archivo.contarRegistros(); i++) {
                    Proveedor reg = archivo.leerRegistro(i);

                    if (reg.get_cuit() == cuit) {
                        reg.mostrar();
                        encontrado = true;
                    }
                }

                if (!encontrado) cout << "No se encontro un proveedor con ese cuit." << endl;

                system("pause");
            }
        }

        system("cls");
        cout << "1: Aniadir" << endl;
        cout << "2: Eliminar" << endl;
        cout << "3: Listar proveedores" << endl;
        cout << "4: Consultar proveedor por cuit" << endl;
        cout << "0: Volver al menu principal" << endl;
        cout << "Ingrese opcion:" << endl;
        cin >> opcion;
    }
}


#endif // SUBMENUPROVEEDORES_H_INCLUDED
