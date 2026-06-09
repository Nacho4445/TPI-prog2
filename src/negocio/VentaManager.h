#pragma once
#include "archivos/ArchivoVenta.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoDetalleVenta.h"

class VentaManager {
private:
   Venta crearVenta();
   void mostrarVenta(Venta &reg);
   void ordenarVentas(Venta vVentas[], int cantidad);
   ArchivoVenta _archivoVentas;
   ArchivoEquipo _archivoEquipos;
   ArchivoDetalleVenta _archivoDetalleVentas;

public:
	VentaManager();

   void guardarVenta();
   void listarVentas();
   void modificarVenta();
   void eliminarVenta();
   void mostrarVentasOrdenadas();

};
