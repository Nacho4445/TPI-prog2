#pragma once
#include "archivos/ArchivoVenta.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoDetalleVenta.h"
#include "archivos/ArchivoTipoMarca.h"
#include "archivos/ArchivoTipoEquipo.h"
#include "utils/Consola.h"
#include "utils/Validador.h"

class VentaManager {
private:
   Venta crearVenta();
   Validador validador;
   void mostrarVenta(Venta &reg, DetalleVenta *detalles);
   void ordenarVentas(Venta vVentas[], int cantidad);

   const char* obtenerNombreMarca(int idMarca);
   const char* obtenerNombreTipoEquipo(int idTipoEquipo);
   void mostrarEquipoDetalle(int idEquipo);

   ArchivoVenta _archivoVentas;
   ArchivoEquipo _archivoEquipos;
   ArchivoDetalleVenta _archivoDetalleVentas;
   ArchivoTipoMarca _archivoTipoMarcas;
   ArchivoTipoEquipo _archivoTipoEquipos;

   Consola consola;

public:
    VentaManager();

    void guardarVenta();
    void listarVentas();
    void cancelarVenta();
    void mostrarVentasOrdenadas();

    void consultarPorId();
    void consultarPorCliente();
    void consultarPorEmpleado();
    void consultarPorFecha();
    void consultarPorEquipo();
};
