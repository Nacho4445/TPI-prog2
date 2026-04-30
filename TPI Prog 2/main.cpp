#include <iostream>
#include <vector>
#include "cliente.h"
#include "equipos.h"
#include "ventas.h"

using namespace std;

int main() {
    vector<Cliente> clientes;
    vector<Equipos> equipos;
    vector<Venta> ventas;

    int opcion;
    do {
        cout << "\n=== MENU DE GESTION ===\n";
        cout << "1. Gestionar Clientes\n";
        cout << "2. Gestionar Equipos\n";
        cout << "3. Registrar Venta\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: { // Submenu Clientes
                int opcionClientes;
                do {
                    cout << "\n--- Gestion de Clientes ---\n";
                    cout << "1. Agregar Cliente\n";
                    cout << "2. Ver lista de clientes\n";
                    cout << "0. Volver al menu principal\n";
                    cout << "Seleccione una opcion: ";
                    cin >> opcionClientes;

                    switch (opcionClientes) {
                        case 1: {
                            Cliente c1;
                            //c1.guardar("clientes.dat"); // seg�n apunte Archivos
                            cout << "Cliente agregado correctamente.\n";
                            break;
                        }
                        case 2: {
                            cout << "Listando clientes...\n";
                            break;
                        }
                        case 0: {
                            cout << "Volviendo al menu principal...\n";
                            break;
                        }
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (opcionClientes != 0);
                break;
            }
            case 2: { // Submenu Equipos
                int opcionProductos;
                do {
                    cout << "\n--- Gestion de Equipos ---\n";
                    cout << "1. Agregar Producto\n";
                    cout << "0. Volver al menu principal\n";
                    cout << "Seleccione una opcion: ";
                    cin >> opcionProductos;

                    switch (opcionProductos) {
                        case 1: {
                            int codigo, stock;
                            string descripcion, marca, tipoEquipo;

                            cout << "Ingrese numero de equipo (codigo unico): ";
                            cin >> codigo;
                            cin.ignore();

                            cout << "Ingrese descripcion del equipo: ";
                            //cin >> descripcion;

                            cout << "Ingrese marca: ";
                            //cin >> marca;

                            cout << "Ingrese tipo de equipo (PC, notebook, impresora, etc.): ";
                            //cin >> tipoEquipo;

                            cout << "Ingrese cantidad de unidades disponibles: ";
                            cin >> stock;
                            cin.ignore();

                            break;
                        }
                        case 0:
                            cout << "Volviendo al menu principal...\n";
                            break;
                        default:
                            cout << "Opcion invalida.\n";
                    }
                } while (opcionProductos != 0);
                break;
            }
            case 3: { // Registrar Venta
                // Código para registrar venta
                break;
            }
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
