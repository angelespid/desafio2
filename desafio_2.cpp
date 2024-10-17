#include<iostream>
#include<cstring>

using namespace std;
class Surtidor;  
class Venta;

class redNacional{
    private://atributos
        string* estaciones;
        int capacidad;
        int totalEstaciones;
        void redimensionar();
    public://metodos
        redNacional();
        ~redNacional();
        void mostrarRedenacional() const;
        void agregarEstacion(string nombre);
        void eliminarEstacion(string nombre);
        
};

class EstacionServicio{
    private:
        string nombre,codigo, region;
        float precioCorriente,precioDiesel,precioExtra;
        Surtidor*surtidores;
        int NumSurtidores;
    public:
        EstacionServicio(string,string,string,float,float,float);
        void agregarSurtidor();
        void fijarPrecio();
        void ventaTotal();
        void activarSurtidor();
        void VenderProducto();
};

class Surtidor{
    private:
        string codigo;
        bool activo;
        Venta*ventas;
    public:

        void registrarVentas();
        void mostrarVentas();
        void activar();
        void desactivar();
        
};
class Tanque{
    private:
        int capacidadDiesel, capacidadCorriente, capacidadExtra;
        int litrosDiesel, litrosCorriente, litrosExtra;

    public:
        Tanque(int capacidadDiesel, int capacidadCorriente, int capacidadExtra);
        void capacidadTanque();
        void capacidadActual();
};


class Venta{
    private:
        string fecha,hora,nombreCliente,tipoCombustible;
        float cantidaCombustible, valorTotal;
    public:
        void registrarVenta();
        void mostrarVenta();    

        
        
};
//contructor redNacional


int main(){
redNacional mired;

    mired.agregarEstacion("Estacion Norte");
    mired.mostrarRedenacional();
    mired.eliminarEstacion("Estacion Norte");
    mired.mostrarRedenacional();



    return 0;
}
//constructor
redNacional::redNacional() {
    capacidad = 2;  // Capacidad inicial del arreglo dinámico
    totalEstaciones = 0;  // Inicialmente no hay estaciones
    estaciones = new string[capacidad];  // Arreglo dinámico de strings
}

// Destructor
redNacional::~redNacional() {
    delete[] estaciones;  // Liberamos la memoria al destruir el objeto
}

// Método para agregar una nueva estación
void redNacional::agregarEstacion(string nombre) {
    if (totalEstaciones == capacidad) {
        redimensionar();  // Si no hay espacio, redimensionamos el arreglo
    }
    estaciones[totalEstaciones] = nombre;  // Añadimos la nueva estación
    totalEstaciones++;  // Incrementamos el número de estaciones
    cout << "Estacion " << nombre << " agregada a la red." << endl;
}

// Método para redimensionar el arreglo dinámico
void redNacional::redimensionar() {
    int nuevaCapacidad = capacidad * 2;  // Duplicamos la capacidad
    string* nuevoArreglo = new string[nuevaCapacidad];  // Creamos un nuevo arreglo dinámico

    // Copiamos los datos del arreglo viejo al nuevo
    for (int i = 0; i < totalEstaciones; i++) {
        nuevoArreglo[i] = estaciones[i];
    }

    // Liberamos la memoria del arreglo viejo
    delete[] estaciones;

    // Actualizamos los punteros y la capacidad
    estaciones = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

// Método para mostrar todas las estaciones registradas en la red
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

// Elimina un estacion
void redNacional::eliminarEstacion(string nombre) {
    bool encontrada = false;
    for (int i = 0; i < totalEstaciones; i++) {
        if (estaciones[i] == nombre) {
            encontrada = true;
            // Desplazamos todas las estaciones hacia la izquierda
            for (int j = i; j < totalEstaciones - 1; j++) {
                estaciones[j] = estaciones[j + 1];
            }
            totalEstaciones--;  // Reducimos el número de estaciones
            cout << "Se ha eliminado la estacion: " << nombre << endl;
            break;
        }
    }
    if (!encontrada) {
        cout << "No se encontró ninguna estación con el nombre: " << nombre << endl;
    }
}