#include<iostream>
#include<cstring>

using namespace std;

class Surtidor;  // Declaración anticipada
class Venta;

// Clase RedNacional
class redNacional {
private:
    string* estaciones;
    int capacidad;
    int totalEstaciones;
    void redimensionar();
public:
    redNacional();
    ~redNacional();
    void mostrarRedenacional() const;
    void agregarEstacion(string nombre);
    void eliminarEstacion(string nombre);  // Solo si no tiene surtidores activos
};

// Clase EstacionServicio
class EstacionServicio {
private:
    string nombre, codigo, region;
    float precioCorriente, precioDiesel, precioExtra;
    Surtidor* surtidores;
    int numSurtidores;
    int capacidadSurtidores;
public:
    EstacionServicio(string, string, string, float, float, float);
    ~EstacionServicio();
    void agregarSurtidor(string codigo);
    void fijarPrecio(float corriente, float diesel, float extra);
    void mostrarSurtidores() const;
    void activarSurtidor(string codigo);
    void desactivarSurtidor(string codigo);
    void redimensionarSurtidores();
    bool tieneSurtidoresActivos() const;  // Método para validar si hay surtidores activos
};

// Clase Surtidor
class Surtidor {
private:
    string codigo;
    bool activo;
    Venta* ventas;
    int numVentas;
    int capacidadVentas;

public:
    Surtidor();
    Surtidor(string codigo);
    ~Surtidor();
    string getCodigo() const;  // Método para obtener el código del surtidor
    void mostrarSurtidor() const;
    void registrarVenta(string fecha, string hora, string nombreCliente, string tipoCombustible, float cantidadCombustible, float valorTotal);
    void mostrarVentas() const;
    void activar();
    void desactivar();
    bool estaActivo() const;
    void redimensionarVentas();
};

// Clase Tanque
class Tanque {
private:
    int capacidadDiesel, capacidadCorriente, capacidadExtra;
    int litrosDiesel, litrosCorriente, litrosExtra;

public:
    Tanque(int capacidadDiesel, int capacidadCorriente, int capacidadExtra);
    void capacidadTanque() const;
    void capacidadActual() const;
    bool restarCombustible(string tipoCombustible, float litros);
};

// Clase Venta
class Venta {
private:
    string fecha, hora, nombreCliente, tipoCombustible;
    float cantidadCombustible;
    float valorTotal;

public:
    Venta();
    Venta(string fecha, string hora, string nombreCliente, string tipoCombustible, float cantidadCombustible, float valorTotal);
    void mostrarVenta() const;
};
void mostrarMenu() {
    cout << "\n===== Menu Red Nacional =====" << endl;
    cout << "1. Agregar estación de servicio" << endl;
    cout << "2. Eliminar estación de servicio" << endl;
    cout << "3. Mostrar estaciones de servicio" << endl;
    cout << "4. Agregar surtidor a una estación" << endl;
    cout << "5. Activar surtidor" << endl;
    cout << "6. Desactivar surtidor" << endl;
    cout << "7. Registrar venta de combustible" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opción: ";
}
// Función principal
int main() {
    redNacional mired;  // Crear una instancia de la red nacional de estaciones
    EstacionServicio* estacionActual = nullptr;  // Estación actual seleccionada (opcional)

    int opcion;
    string nombreEstacion, codigoSurtidor;
    string fecha, hora, nombreCliente, tipoCombustible;
    float cantidadCombustible, precioLitro, valorTotal;

    do {
        mostrarMenu();
        cin >> opcion;

        switch(opcion) {
            case 1:  // Agregar estación de servicio
                cout << "Ingrese el nombre de la nueva estación: ";
                cin >> nombreEstacion;
                mired.agregarEstacion(nombreEstacion);
                break;
            case 2:  // Eliminar estación de servicio
                cout << "Ingrese el nombre de la estación a eliminar: ";
                cin >> nombreEstacion;
                mired.eliminarEstacion(nombreEstacion);
                break;
            case 3:  // Mostrar estaciones
                mired.mostrarRedenacional();
                break;
            case 4:  // Agregar surtidor a una estación
                cout << "Ingrese el nombre de la estación para agregar un surtidor: ";
                cin >> nombreEstacion;
                cout << "Ingrese el código del surtidor: ";
                cin >> codigoSurtidor;
                // Aquí agregaríamos lógica para buscar la estación por nombre y agregar el surtidor
                // estaciónActual->agregarSurtidor(codigoSurtidor);
                cout << "Surtidor agregado (simulación)." << endl;  // Este mensaje es una simulación.
                break;
            case 5:  // Activar surtidor
                cout << "Ingrese el código del surtidor a activar: ";
                cin >> codigoSurtidor;
                // Lógica para activar surtidor
                // estaciónActual->activarSurtidor(codigoSurtidor);
                cout << "Surtidor activado (simulación)." << endl;  // Simulación.
                break;
            case 6:  // Desactivar surtidor
                cout << "Ingrese el código del surtidor a desactivar: ";
                cin >> codigoSurtidor;
                // Lógica para desactivar surtidor
                // estaciónActual->desactivarSurtidor(codigoSurtidor);
                cout << "Surtidor desactivado (simulación)." << endl;  // Simulación.
                break;
            case 7:  // Registrar venta de combustible
                cout << "Ingrese la fecha de la venta (dd/mm/yyyy): ";
                cin >> fecha;
                cout << "Ingrese la hora de la venta (hh:mm): ";
                cin >> hora;
                cout << "Ingrese el nombre del cliente: ";
                cin >> nombreCliente;
                cout << "Ingrese el tipo de combustible (Diesel/Corriente/Extra): ";
                cin >> tipoCombustible;
                cout << "Ingrese la cantidad de litros: ";
                cin >> cantidadCombustible;
                cout << "Ingrese el precio por litro: ";
                cin >> precioLitro;

                valorTotal = cantidadCombustible * precioLitro;
                // Lógica para registrar la venta en un surtidor
                // estaciónActual->registrarVenta(fecha, hora, nombreCliente, tipoCombustible, cantidadCombustible, valorTotal);
                cout << "Venta registrada por " << valorTotal << " unidades monetarias (simulación)." << endl;  // Simulación.
                break;
            case 0:  // Salir
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }

    } while(opcion != 0);  // El menú se repetirá hasta que se elija la opción de salir

    return 0;
}

// Implementación de redNacional
redNacional::redNacional() {
    capacidad = 2;
    totalEstaciones = 0;
    estaciones = new string[capacidad];
}

redNacional::~redNacional() {
    delete[] estaciones;
}

void redNacional::agregarEstacion(string nombre) {
    if (totalEstaciones == capacidad) {
        redimensionar();
    }
    estaciones[totalEstaciones] = nombre;
    totalEstaciones++;
    cout << "Estacion " << nombre << " agregada a la red." << endl;
}

void redNacional::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    string* nuevoArreglo = new string[nuevaCapacidad];
    for (int i = 0; i < totalEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }
    delete[] estaciones;
    estaciones = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

void redNacional::mostrarRedenacional() const {
    if (totalEstaciones == 0) {
        cout << "No hay estaciones registradas en la red." << endl;
    } else {
        cout << "Estaciones en la Red Nacional: " << endl;
        for (int i = 0; i < totalEstaciones; i++) {
            cout << "- " << estaciones[i] << endl;
        }
    }
}

void redNacional::eliminarEstacion(string nombre) {
    bool encontrada = false;
    for (int i = 0; i < totalEstaciones; i++) {
        if (estaciones[i] == nombre) {
            encontrada = true;
            // Desplazamos las estaciones hacia la izquierda
            for (int j = i; j < totalEstaciones - 1; j++) {
                estaciones[j] = estaciones[j + 1];
            }
            totalEstaciones--;
            cout << "Se ha eliminado la estacion: " << nombre << endl;
            break;
        }
    }
    if (!encontrada) {
        cout << "No se encontró ninguna estación con el nombre: " << nombre << endl;
    }
}

// Implementación de EstacionServicio
EstacionServicio::EstacionServicio(string _nombre, string _codigo, string _region, float _precioCorriente, float _precioDiesel, float _precioExtra)
    : nombre(_nombre), codigo(_codigo), region(_region), precioCorriente(_precioCorriente), precioDiesel(_precioDiesel), precioExtra(_precioExtra) {
    capacidadSurtidores = 2;
    numSurtidores = 0;
    surtidores = new Surtidor[capacidadSurtidores];
}

EstacionServicio::~EstacionServicio() {
    delete[] surtidores;
}

void EstacionServicio::agregarSurtidor(string codigoSurtidor) {
    if (numSurtidores == capacidadSurtidores) {
        redimensionarSurtidores();
    }
    surtidores[numSurtidores] = Surtidor(codigoSurtidor);
    numSurtidores++;
    cout << "Surtidor " << codigoSurtidor << " agregado a la estación." << endl;
}

void EstacionServicio::fijarPrecio(float corriente, float diesel, float extra) {
    precioCorriente = corriente;
    precioDiesel = diesel;
    precioExtra = extra;
    cout << "Precios fijados: Corriente = " << corriente << ", Diesel = " << diesel << ", Extra = " << extra << endl;
}

void EstacionServicio::mostrarSurtidores() const {
    if (numSurtidores == 0) {
        cout << "No hay surtidores en esta estación." << endl;
    } else {
        cout << "Surtidores en la estación: " << endl;
        for (int i = 0; i < numSurtidores; i++) {
            surtidores[i].mostrarSurtidor();
        }
    }
}

void EstacionServicio::activarSurtidor(string codigo) {
    for (int i = 0; i < numSurtidores; i++) {
        if (surtidores[i].estaActivo() == false && surtidores[i].getCodigo() == codigo) {
            surtidores[i].activar();
            cout << "Surtidor " << codigo << " activado." << endl;
            return;
        }
    }
    cout << "No se encontró el surtidor con código: " << codigo << endl;
}

void EstacionServicio::desactivarSurtidor(string codigo) {
    for (int i = 0; i < numSurtidores; i++) {
        if (surtidores[i].estaActivo() == true && surtidores[i].getCodigo() == codigo) {
            surtidores[i].desactivar();
            cout << "Surtidor " << codigo << " desactivado." << endl;
            return;
        }
    }
    cout << "No se encontró el surtidor con código: " << codigo << endl;
}

void EstacionServicio::redimensionarSurtidores() {
    int nuevaCapacidad = capacidadSurtidores * 2;
    Surtidor* nuevoArreglo = new Surtidor[nuevaCapacidad];
    for (int i = 0; i < numSurtidores; i++) {
        nuevoArreglo[i] = surtidores[i];
    }
    delete[] surtidores;
    surtidores = nuevoArreglo;
    capacidadSurtidores = nuevaCapacidad;
}

bool EstacionServicio::tieneSurtidoresActivos() const {
    for (int i = 0; i < numSurtidores; i++) {
        if (surtidores[i].estaActivo()) {
            return true;
        }
    }
    return false;
}

// Implementación de Surtidor
Surtidor::Surtidor() : codigo("SIN_CODIGO"), activo(false), numVentas(0), capacidadVentas(2) {
    ventas = new Venta[capacidadVentas];
}

Surtidor::Surtidor(string _codigo) : codigo(_codigo), activo(true), numVentas(0), capacidadVentas(2) {
    ventas = new Venta[capacidadVentas];
}

Surtidor::~Surtidor() {
    delete[] ventas;
}

string Surtidor::getCodigo() const {
    return codigo;
}

void Surtidor::mostrarSurtidor() const {
    cout << "Surtidor: " << codigo << " | Activo: " << (activo ? "Si" : "No") << endl;
}

void Surtidor::registrarVenta(string fecha, string hora, string nombreCliente, string tipoCombustible, float cantidadCombustible, float valorTotal) {
    if (numVentas == capacidadVentas) {
        redimensionarVentas();
    }
    ventas[numVentas] = Venta(fecha, hora, nombreCliente, tipoCombustible, cantidadCombustible, valorTotal);
    numVentas++;
    cout << "Venta registrada: " << cantidadCombustible << " litros de " << tipoCombustible << " por " << valorTotal << " unidades monetarias." << endl;
}

void Surtidor::mostrarVentas() const {
    if (numVentas == 0) {
        cout << "No se han registrado ventas." << endl;
    } else {
        for (int i = 0; i < numVentas; i++) {
            ventas[i].mostrarVenta();
        }
    }
}

void Surtidor::activar() {
    activo = true;
}

void Surtidor::desactivar() {
    activo = false;
}

bool Surtidor::estaActivo() const {
    return activo;
}

void Surtidor::redimensionarVentas() {
    int nuevaCapacidad = capacidadVentas * 2;
    Venta* nuevoArreglo = new Venta[nuevaCapacidad];
    for (int i = 0; i < numVentas; i++) {
        nuevoArreglo[i] = ventas[i];
    }
    delete[] ventas;
    ventas = nuevoArreglo;
    capacidadVentas = nuevaCapacidad;
}

// Implementación de Tanque
Tanque::Tanque(int _capacidadDiesel, int _capacidadCorriente, int _capacidadExtra)
    : capacidadDiesel(_capacidadDiesel), capacidadCorriente(_capacidadCorriente), capacidadExtra(_capacidadExtra),
      litrosDiesel(_capacidadDiesel), litrosCorriente(_capacidadCorriente), litrosExtra(_capacidadExtra) {}

void Tanque::capacidadTanque() const {
    cout << "Capacidad total: Diesel = " << capacidadDiesel << "L, Corriente = " << capacidadCorriente << "L, Extra = " << capacidadExtra << "L." << endl;
}

void Tanque::capacidadActual() const {
    cout << "Capacidad actual: Diesel = " << litrosDiesel << "L, Corriente = " << litrosCorriente << "L, Extra = " << litrosExtra << "L." << endl;
}

bool Tanque::restarCombustible(string tipoCombustible, float litros) {
    if (tipoCombustible == "Diesel" && litrosDiesel >= litros) {
        litrosDiesel -= litros;
        return true;
    } else if (tipoCombustible == "Corriente" && litrosCorriente >= litros) {
        litrosCorriente -= litros;
        return true;
    } else if (tipoCombustible == "Extra" && litrosExtra >= litros) {
        litrosExtra -= litros;
        return true;
    } else {
        cout << "No hay suficiente " << tipoCombustible << " disponible." << endl;
        return false;
    }
}

// Implementación de Venta
Venta::Venta() : fecha("N/A"), hora("N/A"), nombreCliente("N/A"), tipoCombustible("N/A"), cantidadCombustible(0), valorTotal(0) {}

Venta::Venta(string _fecha, string _hora, string _nombreCliente, string _tipoCombustible, float _cantidadCombustible, float _valorTotal)
    : fecha(_fecha), hora(_hora), nombreCliente(_nombreCliente), tipoCombustible(_tipoCombustible), cantidadCombustible(_cantidadCombustible), valorTotal(_valorTotal) {}

void Venta::mostrarVenta() const {
    cout << "Fecha: " << fecha << ", Hora: " << hora << ", Cliente: " << nombreCliente
         << ", Tipo de combustible: " << tipoCombustible << ", Cantidad: " << cantidadCombustible
         << "L, Valor total: " << valorTotal << " unidades monetarias." << endl;
}
