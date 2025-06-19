#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED

#include "archivoProductos.h"

void submenuProductos() {
    ArchivoProductos archivo("productos.dat");

    system("cls");
    int opcion;
    cout << "1: Aniadir" << endl;
    cout << "2: Eliminar" << endl;
    cout << "3: Listar productos" << endl;
    cout << "4: Listar productos por mayor cantidad de stock" << endl;
    cout << "5: Listar productos por menor cantidad de stock" << endl;
    cout << "6: Listar productos por precio mas alto" << endl;
    cout << "7: Listar productos por precio mas bajo" << endl;
    cout << "8: Consultar productos por numero" << endl;
    cout << "9: Consultar productos por tipo" << endl;
    cout << "0: Volver al menu principal" << endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;

    while (opcion != 0) {
        system("cls");
        switch(opcion) {
        case 1:
            {
                Producto reg;
                reg.cargar();

                if (archivo.agregarRegistro(reg))
                    cout << "Registro aniadido correctamente." << endl;
                else
                    cout << "Hubo un error al aniadir el registro." << endl;

                system("pause");
            }
            break;
        case 2:
            {
                int numero;
                cout << "Ingrese numero del producto a eliminar: " << endl;
                cin >> numero;

                archivo.eliminarRegistro(archivo.posicionRegistro(numero));
            }
            break;
        case 3:
            {
                cout << "Registros de productos: " << endl << endl;
                for (int i = 0; i < archivo.contarRegistros(); i++) {
                    archivo.leerRegistro(i).mostrar();
                    cout << endl;
                }

                system("pause");
            }
            break;
        case 4:
            {
                cout << "Registros de productos (por mayor stock): " << endl << endl;

                Productos* regs = archivo.obtenerRegistros();


                delete[] regs;


            }
        }
    }
}

#endif // SUBMENUPRODUCTOS_H_INCLUDED
