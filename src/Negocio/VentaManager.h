#pragma once
#include "Archivos/ArchivoVenta.h"

class VentaManager {
private:
   Venta crearVenta();
   void mostrarVenta(Venta &reg);
   void ordenarVentas(Venta vVentas[], int cantidad);
   ArchivoVenta _archivoVentas;

public:
	VentaManager();

   void guardarVenta();
   void listarVentas();
   void modificarVenta();
   void mostrarVentasOrdenadas();


};
