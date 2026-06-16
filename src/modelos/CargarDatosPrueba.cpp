#include "CargarDatosPrueba.h"

#include "archivos/ArchivoTipoCliente.h"
#include "archivos/ArchivoTipoMarca.h"
#include "archivos/ArchivoTipoEquipo.h"
#include "archivos/ArchivoCliente.h"
#include "archivos/ArchivoEmpleado.h"
#include "archivos/ArchivoEquipo.h"
#include "archivos/ArchivoVenta.h"
#include "archivos/ArchivoDetalleVenta.h"

#include "modelos/TipoCliente.h"
#include "modelos/TipoMarca.h"
#include "modelos/TipoEquipo.h"
#include "modelos/Cliente.h"
#include "modelos/Empleado.h"
#include "modelos/Equipo.h"
#include "modelos/Venta.h"
#include "modelos/DetalleVenta.h"

#include "utils/Direccion.h"
#include "utils/Fecha.h"

#include <iostream>
using namespace std;

void CargarDatosPrueba::cargarDatosPrueba(){

    ArchivoTipoCliente archivoTipoCliente;
    ArchivoTipoMarca archivoTipoMarca;
    ArchivoTipoEquipo archivoTipoEquipo;
    ArchivoCliente archivoCliente;
    ArchivoEmpleado archivoEmpleado;
    ArchivoEquipo archivoEquipo;
    ArchivoVenta archivoVenta;
    ArchivoDetalleVenta archivoDetalleVenta;

    // Vaciar archivos para no duplicar datos.
    archivoTipoCliente.vaciar();
    archivoTipoMarca.vaciar();
    archivoTipoEquipo.vaciar();
    archivoCliente.vaciar();
    archivoEmpleado.vaciar();
    archivoEquipo.vaciar();
    archivoDetalleVenta.vaciar();

    // OJO: ArchivoVenta no tiene vaciar().
    // Por ahora borr� manualmente datos/ventas.dat antes de ejecutar esto,
    // o agregamos despu�s un vaciar() a ArchivoVenta.

    // ---------------- TIPOS CLIENTE ----------------
    archivoTipoCliente.guardar(TipoCliente(1, "Particular", true));
    archivoTipoCliente.guardar(TipoCliente(2, "Empresa", true));

    // ---------------- MARCAS ----------------
    archivoTipoMarca.guardar(TipoMarca(1, "Samsung", true));
    archivoTipoMarca.guardar(TipoMarca(2, "Apple", true));
    archivoTipoMarca.guardar(TipoMarca(3, "Motorola", true));
    archivoTipoMarca.guardar(TipoMarca(4, "Lenovo", true));
    archivoTipoMarca.guardar(TipoMarca(5, "HP", true));

    // ---------------- TIPOS EQUIPO ----------------
    archivoTipoEquipo.guardar(TipoEquipo(1, "Celular", true));
    archivoTipoEquipo.guardar(TipoEquipo(2, "Notebook", true));
    archivoTipoEquipo.guardar(TipoEquipo(3, "Tablet", true));
    archivoTipoEquipo.guardar(TipoEquipo(4, "Monitor", true));

    // ---------------- CLIENTES ----------------
    Direccion d1("Cespedes", 123, "PB", "1", "General Pacheco", "1617", "Buenos Aires", true);
    Cliente c1(1, 1);
    c1.setCuit(20156497854);
    c1.setNombre("Florencia");
    c1.setApellido("Alvarez");
    c1.setTelefono("1564978548");
    c1.setEmail("prueba@prueba.com");
    c1.setDireccion(d1);
    c1.setEstado(true);
    archivoCliente.guardar(c1);

    Direccion d2("Avellaneda", 456, "1", "A", "Tigre", "1648", "Buenos Aires", true);
    Cliente c2(2, 1);
    c2.setCuit(20333444555);
    c2.setNombre("Juan");
    c2.setApellido("Perez");
    c2.setTelefono("1122334455");
    c2.setEmail("juan@mail.com");
    c2.setDireccion(d2);
    c2.setEstado(true);
    archivoCliente.guardar(c2);

    Direccion d3("San Martin", 800, "2", "B", "San Fernando", "1646", "Buenos Aires", true);
    Cliente c3(3, 2);
    c3.setCuit(30777111222);
    c3.setNombre("TecnoSur");
    c3.setApellido("SRL");
    c3.setTelefono("1144556677");
    c3.setEmail("contacto@tecnosur.com");
    c3.setDireccion(d3);
    c3.setEstado(true);
    archivoCliente.guardar(c3);

    // ---------------- EMPLEADOS ----------------
    Direccion de1("Mitre", 100, "PB", "1", "Benavidez", "1621", "Buenos Aires", true);
    Empleado e1(1);
    e1.setCuit(20222111333);
    e1.setNombre("Carlos");
    e1.setApellido("Gomez");
    e1.setTelefono("1166667777");
    e1.setEmail("carlos@empresa.com");
    e1.setDireccion(de1);
    e1.setEstado(true);
    archivoEmpleado.guardar(e1);

    Direccion de2("Italia", 250, "1", "C", "Tigre", "1648", "Buenos Aires", true);
    Empleado e2(2);
    e2.setCuit(20299888777);
    e2.setNombre("Ana");
    e2.setApellido("Lopez");
    e2.setTelefono("1155554444");
    e2.setEmail("ana@empresa.com");
    e2.setDireccion(de2);
    e2.setEstado(true);
    archivoEmpleado.guardar(e2);

    // ---------------- EQUIPOS ----------------
    archivoEquipo.guardar(Equipo(1, 1, 1, "Galaxy A15", 20, 250000, true));      // Samsung Celular
    archivoEquipo.guardar(Equipo(2, 1, 2, "iPhone 13", 10, 650000, true));       // Apple Celular
    archivoEquipo.guardar(Equipo(3, 2, 4, "ThinkPad E14", 8, 850000, true));     // Lenovo Notebook
    archivoEquipo.guardar(Equipo(4, 2, 5, "HP Pavilion", 6, 780000, true));      // HP Notebook
    archivoEquipo.guardar(Equipo(5, 3, 1, "Galaxy Tab A9", 12, 320000, true));   // Samsung Tablet
    archivoEquipo.guardar(Equipo(6, 4, 1, "Monitor Samsung 24", 15, 210000, true));

    // ---------------- VENTAS ----------------
    archivoVenta.guardar(Venta(1, 1, 1, Fecha(13, 6, 2026), 500000, true));
    archivoVenta.guardar(Venta(2, 2, 1, Fecha(13, 6, 2026), 650000, true));
    archivoVenta.guardar(Venta(3, 3, 2, Fecha(13, 6, 2026), 1060000, true));

    // ---------------- DETALLES DE VENTA ----------------
    archivoDetalleVenta.guardar(DetalleVenta(1, 1, 1, 2, 250000, 500000, true));

    archivoDetalleVenta.guardar(DetalleVenta(2, 2, 2, 1, 650000, 650000, true));

    archivoDetalleVenta.guardar(DetalleVenta(3, 3, 3, 1, 850000, 850000, true));
    archivoDetalleVenta.guardar(DetalleVenta(4, 3, 6, 1, 210000, 210000, true));

    cout << "Datos de prueba cargados correctamente." << endl;
}
