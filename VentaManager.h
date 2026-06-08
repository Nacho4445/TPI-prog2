#pragma once
#include "ArchivoVenta.h"

class VentaManager {
private:
   Venta crearVenta();
   void mostrarVenta(const Venta &reg);
   void ordenarVentas(Venta vVentas[], int cantidad);
   ArchivoVenta _archivoVentas;

public:
	VentaManager();

   void guardarVenta();
   void listarVentas();
   void modificarVenta();
   void mostrarVentasOrdenadas();


};
