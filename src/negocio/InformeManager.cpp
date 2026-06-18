#include <iostream>
#include "negocio/InformeManager.h"
#include "archivos/ArchivoCliente.h"
#include "archivos/ArchivoEmpleado.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoVenta.h"
#include "modelos/RecaudacionAnual.h"
#include "modelos/RecaudacionClientes.h"
#include "modelos/StockEquipos.h"
#include "archivos/ArchivoDetalleVenta.h"
#include "modelos/DetalleVenta.h"

using namespace std;

// Genera un informe con la recaudación total correspondiente
// a cada año registrado en las ventas.
//
// El informe se muestra por pantalla y se guarda en el archivo
// "informes/recaudacionAnual.dat".
//
// VALIDACIONES:
// - Verifica que existan ventas activas.
// - Comprueba que el archivo de informe pueda crearse correctamente.
void InformeManager::recaudacionXanio(){

    ArchivoVenta repoVentas;
    int cantidadVentas = repoVentas.getCantidadRegistros();
    int anioMin = 9999;
    int anioMax = 0;

    // Busca el primer y el último año con ventas activas.
    for(int i = 0; i < cantidadVentas; i++){

        Venta venta = repoVentas.leerPorPosicion(i);

        if(venta.getEstado()){

            int anio = venta.getFecha().getAnio();

            if(anio < anioMin){
                anioMin = anio;
            }

            if(anio > anioMax){
                anioMax = anio;
            }
        }
    }

    // Verifica que existan ventas activas.
    if(anioMin == 9999){
        cout << "No hay ventas activas." << endl;
        consola.pausar();
        return;
    }

    FILE *p = fopen("informes/recaudacionAnual.dat", "wb");

    // Verifica que el archivo pueda crearse correctamente.
    if(p == nullptr){
        cout << "Error de informe..." << endl;
        consola.pausar();
        return;
    }

    // Calcula la recaudación correspondiente a cada año.
    for(int anio = anioMin; anio <= anioMax; anio++){

        float recaudacion = 0;

        for(int i = 0; i < cantidadVentas; i++){

            Venta venta = repoVentas.leerPorPosicion(i);

            if(venta.getEstado() &&
               venta.getFecha().getAnio() == anio){

                recaudacion += venta.getImporteTotal();
            }
        }

        cout << "------------------------" << endl;
        cout << "Anio: " << anio << endl;
        cout << "Recaudacion: $" << recaudacion << endl;
        cout << "------------------------" << endl;

        RecaudacionAnual reg(recaudacion, anio);
        fwrite(&reg, sizeof(RecaudacionAnual), 1, p);
    }

    fclose(p);
    consola.pausar();
}

// Genera un informe con la recaudación total por cada cliente.
//
// El informe se muestra por pantalla y se guarda en el archivo
// "informes/recaudacionXcliente.dat".
//
// VALIDACIONES:
// - Verifica que se pueda reservar memoria dinámica.
// - Comprueba que el archivo de informe pueda crearse correctamente.
// - Solo toma ventas activas.
// - Solo muestra clientes activos.
void InformeManager::recaudacionXcliente(){

    ArchivoCliente repoClientes;
    int cantidadClientes = repoClientes.getCantidadRegistros();

    float* pClientes = nullptr;
    pClientes = new float[cantidadClientes]{};

    if(pClientes == nullptr){
        cout << "Error de memoria..." << endl;
        consola.pausar();
        return;
    }

    ArchivoVenta repoVentas;
    int cantidadVentas = repoVentas.getCantidadRegistros();

    // Acumula el importe de las ventas activas en la posición correspondiente al cliente.
    for(int i = 0; i < cantidadVentas; i++){

        Venta venta = repoVentas.leerPorPosicion(i);

        if(venta.getEstado()){
            int pos = repoClientes.buscar(venta.getIdCliente());

            if(pos >= 0){
                pClientes[pos] += venta.getImporteTotal();
            }
        }
    }

    FILE *p = fopen("informes/recaudacionXcliente.dat", "wb");

    if(p == nullptr){
        cout << "Error de informe..." << endl;
        delete[] pClientes;
        consola.pausar();
        return;
    }

    // Guarda y muestra la recaudación acumulada por cliente activo.
    for(int i = 0; i < cantidadClientes; i++){

        Cliente regCliente = repoClientes.leerPorPosicion(i);

        if(regCliente.getEstado()){
            RecaudacionClientes regRecaudacion(pClientes[i], regCliente);
            fwrite(&regRecaudacion, sizeof(RecaudacionClientes), 1, p);

            cout << "------------------------" << endl;
            cout << "Cliente ID: " << regCliente.getIdCliente() << endl;
            cout << "Recaudacion: $" << pClientes[i] << endl;
            cout << "------------------------" << endl;
        }
    }

    fclose(p);
    delete[] pClientes;
    consola.pausar();
}

// Genera un informe con los equipos más vendidos.
//
// Para cada equipo se calcula la cantidad total vendida a partir
// de los detalles de venta. Luego se ordenan de mayor a menor
// según la cantidad vendida.
//
// VALIDACIONES:
// - Verifica que existan equipos cargados.
// - Verifica que existan detalles de venta cargados.
// - Comprueba que se pueda reservar memoria dinámica.
// - Solo toma detalles de venta activos.
void InformeManager::equiposMasVendidos(){

    ArchivoEquipo repoEquipos;
    ArchivoDetalleVenta repoDetalles;

    int cantidadEquipos = repoEquipos.getCantidadEquipos();
    int cantidadDetalles = repoDetalles.getCantidadRegistros();

    if(cantidadEquipos == 0){
        cout << "No hay equipos cargados." << endl;
        consola.pausar();
        return;
    }

    if(cantidadDetalles == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    Equipo *equipos = new Equipo[cantidadEquipos];
    int *cantidadesVendidas = new int[cantidadEquipos];

    if(equipos == nullptr || cantidadesVendidas == nullptr){
        cout << "No se pudo reservar memoria." << endl;

        delete[] equipos;
        delete[] cantidadesVendidas;

        consola.pausar();
        return;
    }

    // Inicializa el vector de equipos y el acumulador de cantidades vendidas.
    for(int i = 0; i < cantidadEquipos; i++){
        equipos[i] = repoEquipos.leerPorPosicion(i);
        cantidadesVendidas[i] = 0;
    }

    // Recorre los detalles de venta para acumular cantidades por equipo.
    for(int i = 0; i < cantidadDetalles; i++){

        DetalleVenta detalle = repoDetalles.leerPorPosicion(i);

        if(!detalle.getEstado()){
            continue;
        }

        for(int j = 0; j < cantidadEquipos; j++){

            if(equipos[j].getIdEquipo() == detalle.getIdEquipo()){
                cantidadesVendidas[j] += detalle.getCantidad();
                break;
            }
        }
    }

    // Ordena los equipos de mayor a menor cantidad vendida.
    for(int i = 0; i < cantidadEquipos - 1; i++){

        for(int j = 0; j < cantidadEquipos - i - 1; j++){

            if(cantidadesVendidas[j] < cantidadesVendidas[j + 1]){

                int auxCantidad = cantidadesVendidas[j];
                cantidadesVendidas[j] = cantidadesVendidas[j + 1];
                cantidadesVendidas[j + 1] = auxCantidad;

                Equipo auxEquipo = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = auxEquipo;
            }
        }
    }

    cout << "========================================" << endl;
    cout << "        EQUIPOS MAS VENDIDOS" << endl;
    cout << "========================================" << endl;

    bool hayVentas = false;

    // Muestra únicamente los equipos que tuvieron ventas.
    for(int i = 0; i < cantidadEquipos; i++){

        if(cantidadesVendidas[i] > 0){

            cout << "Equipo ID: " << equipos[i].getIdEquipo() << endl;
            cout << "Descripcion: " << equipos[i].getDescripcion() << endl;
            cout << "Cantidad vendida: " << cantidadesVendidas[i] << endl;
            cout << "Stock actual: " << equipos[i].getStock() << endl;
            cout << "----------------------------------------" << endl;

            hayVentas = true;
        }
    }

    if(!hayVentas){
        cout << "No hay equipos vendidos." << endl;
    }

    delete[] equipos;
    delete[] cantidadesVendidas;

    consola.pausar();
}

// Genera un informe de ventas realizadas por cada empleado.
//
// Para cada empleado activo se listan las ventas asociadas,
// indicando fecha, importe y tipo de cliente.
// También muestra la cantidad total de ventas y el importe total vendido.
//
// VALIDACIONES:
// - Verifica que existan empleados cargados.
// - Verifica que existan ventas cargadas.
// - Solo toma empleados activos.
// - Solo toma ventas activas.
void InformeManager::ventasXempleado(){

    ArchivoEmpleado repoEmpleados;
    ArchivoVenta repoVentas;
    ArchivoCliente repoClientes;

    int cantidadEmpleados = repoEmpleados.getCantidadRegistros();
    int cantidadVentas = repoVentas.getCantidadRegistros();

    if(cantidadEmpleados == 0){
        cout << "No hay empleados cargados." << endl;
        consola.pausar();
        return;
    }

    if(cantidadVentas == 0){
        cout << "No hay ventas cargadas." << endl;
        consola.pausar();
        return;
    }

    // Recorre todos los empleados.
    for(int i = 0; i < cantidadEmpleados; i++){

        Empleado empleado = repoEmpleados.leerPorPosicion(i);

        if(!empleado.getEstado()){
            continue;
        }

        int cantidadVentasEmpleado = 0;
        double totalVendido = 0;

        cout << "========================================" << endl;
        cout << "Empleado ID: " << empleado.getIdEmpleado() << endl;
        cout << "Empleado: "
             << empleado.getNombre()
             << " "
             << empleado.getApellido() << endl;
        cout << "----------------------------------------" << endl;

        // Busca las ventas realizadas por el empleado actual.
        for(int j = 0; j < cantidadVentas; j++){

            Venta venta = repoVentas.leerPorPosicion(j);

            if(venta.getEstado() &&
               venta.getIdEmpleado() == empleado.getIdEmpleado()){

                Cliente cliente = repoClientes.leer(venta.getIdCliente());

                cout << "Venta Nro " << venta.getIdVenta()
                     << " | Fecha: " << venta.getFecha().toString()
                     << " | Importe: $" << venta.getImporteTotal()
                     << " | Tipo cliente: ";

                // Muestra el tipo de cliente asociado a la venta.
                if(cliente.getTipoCliente() == 1){
                    cout << "Particular";
                }
                else if(cliente.getTipoCliente() == 2){
                    cout << "Empresa";
                }
                else{
                    cout << "No definido";
                }

                cout << endl;

                cantidadVentasEmpleado++;
                totalVendido += venta.getImporteTotal();
            }
        }

        cout << "----------------------------------------" << endl;
        cout << "Cantidad de ventas: " << cantidadVentasEmpleado << endl;
        cout << "Total vendido: $" << totalVendido << endl;
        cout << "========================================" << endl << endl;
    }

    consola.pausar();
}

// Genera un informe con todos los equipos que tienen stock disponible.
//
// El informe se muestra por pantalla y se guarda en el archivo
// "informes/stockDisponible.dat".
//
// VALIDACIONES:
// - Comprueba que el archivo de informe pueda crearse correctamente.
// - Solo toma equipos activos.
// - Solo informa equipos con stock mayor a cero.
void InformeManager::stockDisponible(){

    Equipo regEquipo;
    ArchivoEquipo repoEquipos;
    bool encontro = false;
    int cantidad = repoEquipos.getCantidadEquipos();

    FILE *p = fopen("informes/stockDisponible.dat", "wb");

    if(p == nullptr){
        cout << "Error de informe..." << endl;
        consola.pausar();
        return;
    }

    // Recorre todos los equipos buscando aquellos con stock disponible.
    for(int i = 0; i < cantidad; i++){

        regEquipo = repoEquipos.leerPorPosicion(i);
        int stock = regEquipo.getStock();

        if(regEquipo.getEstado() && stock > 0){

            cout << "------------------------" << endl;
            cout << "Equipo ID: " << regEquipo.getIdEquipo() << endl;
            cout << "Stock disponible: " << stock << endl;
            cout << "------------------------" << endl;

            StockEquipos regStock(regEquipo, stock);
            fwrite(&regStock, sizeof(StockEquipos), 1, p);

            encontro = true;
        }
    }

    if(!encontro){
        cout << "No hay equipos con stock disponible." << endl;
    }

    fclose(p);
    consola.pausar();
}
