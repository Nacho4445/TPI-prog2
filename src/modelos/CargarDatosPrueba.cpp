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
    archivoVenta.vaciar();

    // ---------------- TIPOS CLIENTE ----------------
archivoTipoCliente.guardar(TipoCliente(1, "Particular", true));
archivoTipoCliente.guardar(TipoCliente(2, "Empresa", true));

// ---------------- MARCAS ----------------
archivoTipoMarca.guardar(TipoMarca(1, "Samsung", true));
archivoTipoMarca.guardar(TipoMarca(2, "Apple", true));
archivoTipoMarca.guardar(TipoMarca(3, "Motorola", true));
archivoTipoMarca.guardar(TipoMarca(4, "Lenovo", true));
archivoTipoMarca.guardar(TipoMarca(5, "HP", true));
archivoTipoMarca.guardar(TipoMarca(6, "Dell", true));
archivoTipoMarca.guardar(TipoMarca(7, "Asus", true));
archivoTipoMarca.guardar(TipoMarca(8, "Acer", true));
archivoTipoMarca.guardar(TipoMarca(9, "Xiaomi", true));
archivoTipoMarca.guardar(TipoMarca(10, "Alcatel", true));
archivoTipoMarca.guardar(TipoMarca(11, "AMD", true));
archivoTipoMarca.guardar(TipoMarca(12, "Intel", true));
archivoTipoMarca.guardar(TipoMarca(13, "Sony", true));
archivoTipoMarca.guardar(TipoMarca(14, "LG", true));
archivoTipoMarca.guardar(TipoMarca(15, "Philips", true));
archivoTipoMarca.guardar(TipoMarca(16, "Huawei", true));
archivoTipoMarca.guardar(TipoMarca(17, "Noblex", true));
archivoTipoMarca.guardar(TipoMarca(18, "TCL", true));
archivoTipoMarca.guardar(TipoMarca(19, "JBL", true));
archivoTipoMarca.guardar(TipoMarca(20, "Logitech", true));
archivoTipoMarca.guardar(TipoMarca(21, "Epson", true));
archivoTipoMarca.guardar(TipoMarca(22, "Canon", true));
archivoTipoMarca.guardar(TipoMarca(23, "Brother", true));
archivoTipoMarca.guardar(TipoMarca(24, "Kingston", true));
archivoTipoMarca.guardar(TipoMarca(25, "Seagate", true));
archivoTipoMarca.guardar(TipoMarca(26, "Western Digital", true));
archivoTipoMarca.guardar(TipoMarca(27, "MSI", true));
archivoTipoMarca.guardar(TipoMarca(28, "Gigabyte", true));
archivoTipoMarca.guardar(TipoMarca(29, "Nvidia", true));
archivoTipoMarca.guardar(TipoMarca(30, "Razer", true));

// ---------------- TIPOS EQUIPO ----------------
archivoTipoEquipo.guardar(TipoEquipo(1, "Celular", true));
archivoTipoEquipo.guardar(TipoEquipo(2, "Notebook", true));
archivoTipoEquipo.guardar(TipoEquipo(3, "Tablet", true));
archivoTipoEquipo.guardar(TipoEquipo(4, "Monitor", true));
archivoTipoEquipo.guardar(TipoEquipo(5, "Impresora", true));


// ---------------- CLIENTES ----------------
const char* nombresClientes[30] = {
    "Florencia", "Juan", "Maria", "Lucas", "Camila",
    "Sofia", "Mateo", "Valentina", "Bruno", "Martina",
    "Nicolas", "Agustina", "Federico", "Julieta", "Tomas",
    "Carolina", "Gonzalo", "Rocio", "Martin", "Lucia",
    "TecnoSur", "InfoRed", "CompuMax", "DigitalNet", "ElectroHouse",
    "MegaTech", "ServiPC", "RedPoint", "HardStore", "NetSolutions"
};

const char* apellidosClientes[30] = {
    "Alvarez", "Perez", "Gonzalez", "Ramirez", "Fernandez",
    "Lopez", "Diaz", "Sosa", "Romero", "Torres",
    "Castro", "Medina", "Herrera", "Vega", "Morales",
    "Rojas", "Silva", "Mendez", "Ruiz", "Acosta",
    "SRL", "SA", "SRL", "SA", "SRL",
    "SA", "SRL", "SA", "SRL", "SA"
};

for(int i = 1; i <= 30; i++){
    Direccion dir("Calle Cliente", 100 + i, "PB", "A", "General Pacheco", "1617", "Buenos Aires", true);

    int tipoCliente = (i <= 20) ? 1 : 2;

    Cliente cliente(i, tipoCliente);

    cliente.setCuit(20000000000LL + i);
    cliente.setNombre(nombresClientes[i - 1]);
    cliente.setApellido(apellidosClientes[i - 1]);
    cliente.setTelefono("1122334455");
    cliente.setEmail("cliente@mail.com");
    cliente.setDireccion(dir);
    cliente.setEstado(true);

    archivoCliente.guardar(cliente);
}


// ---------------- EMPLEADOS ----------------
const char* nombresEmpleados[10] = {
    "Carlos", "Ana", "Pablo", "Micaela", "Diego",
    "Laura", "Santiago", "Daniela", "Mariano", "Valeria"
};

const char* apellidosEmpleados[10] = {
    "Gomez", "Lopez", "Martinez", "Suarez", "Ramos",
    "Benitez", "Arias", "Molina", "Paz", "Iglesias"
};

for(int i = 1; i <= 10; i++){
    Direccion dir("Calle Empleado", 200 + i, "1", "B", "Tigre", "1648", "Buenos Aires", true);

    Empleado empleado(i);

    empleado.setCuit(27000000000LL + i);
    empleado.setNombre(nombresEmpleados[i - 1]);
    empleado.setApellido(apellidosEmpleados[i - 1]);
    empleado.setTelefono("1166778899");
    empleado.setEmail("empleado@mail.com");
    empleado.setDireccion(dir);
    empleado.setEstado(true);

    archivoEmpleado.guardar(empleado);
}

// ---------------- EQUIPOS ----------------
archivoEquipo.guardar(Equipo(1, 1, 1, "Galaxy A15", 50, 250000, true));
archivoEquipo.guardar(Equipo(2, 1, 2, "iPhone 13", 45, 650000, true));
archivoEquipo.guardar(Equipo(3, 2, 4, "ThinkPad E14", 40, 850000, true));
archivoEquipo.guardar(Equipo(4, 2, 5, "HP Pavilion", 35, 780000, true));
archivoEquipo.guardar(Equipo(5, 3, 1, "Galaxy Tab A9", 30, 320000, true));
archivoEquipo.guardar(Equipo(6, 4, 1, "Monitor Samsung 24", 25, 210000, true));
archivoEquipo.guardar(Equipo(7, 2, 6, "Dell Inspiron 15", 30, 790000, true));
archivoEquipo.guardar(Equipo(8, 1, 9, "Xiaomi Redmi 13", 60, 220000, true));
archivoEquipo.guardar(Equipo(9, 3, 4, "Lenovo Tab M10", 28, 300000, true));
archivoEquipo.guardar(Equipo(10, 5, 21, "Epson L3250", 20, 280000, true));
archivoEquipo.guardar(Equipo(11, 2, 7, "Asus Vivobook", 24, 740000, true));
archivoEquipo.guardar(Equipo(12, 2, 8, "Acer Aspire 5", 22, 720000, true));
archivoEquipo.guardar(Equipo(13, 1, 3, "Motorola G84", 55, 260000, true));
archivoEquipo.guardar(Equipo(14, 4, 14, "Monitor LG 27", 18, 340000, true));
archivoEquipo.guardar(Equipo(15, 5, 23, "Brother HL1200", 16, 230000, true));

// ---------------- VENTAS Y DETALLES ----------------
int idDetalle = 1;

for(int i = 1; i <= 100; i++){

    int idCliente = ((i - 1) % 30) + 1;
    int idEmpleado = ((i - 1) % 10) + 1;
    int idEquipo = ((i - 1) % 15) + 1;

    Equipo equipo = archivoEquipo.leer(idEquipo);

    int cantidad = (i % 3) + 1;
    float precioUnitario = equipo.getPrecioUnitario();
    float subtotal = precioUnitario * cantidad;

    Fecha fecha((i % 28) + 1, ((i - 1) % 12) + 1, 2026);

    archivoVenta.guardar(Venta(i, idCliente, idEmpleado, fecha, subtotal, true));

    archivoDetalleVenta.guardar(
        DetalleVenta(idDetalle, i, idEquipo, cantidad, precioUnitario, subtotal, true)
    );

    idDetalle++;
  }
}
