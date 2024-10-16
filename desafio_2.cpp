#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RedNacional {
private:
    vector<string> estaciones;  // Lista de estaciones

public:
    // Constructor (puede estar vacío, ya que no necesitamos inicialización)
    RedNacional() {}
    // Destructor
    ~RedNacional() {}
    // Agregar una estación de servicio
    void agregarEstacion(string nombre);
    // Eliminar una estación de servicio por nombre
    void eliminarEstacion(string nombre);
    // Verificar fugas 
    void verificarFugas();
    // Mostrar todas las estaciones de la red
    void mostrarEstaciones();
};

// Agregar una estación
void RedNacional::agregarEstacion(string nombre) {
    estaciones.push_back(nombre);//Es un método de la clase std::vector
    cout << "Estacion " << nombre << " agregada a la red." << endl;
}

// Método para eliminar una estación
void RedNacional::eliminarEstacion(string nombre) {
    for (size_t i = 0; i < estaciones.size(); i++) {
        if (estaciones[i] == nombre) {
            estaciones.erase(estaciones.begin() + i);
            cout << "Estacion " << nombre << " eliminada de la red." << endl;
            return;
        }
    }
    cout << "Estacion " << nombre << " no encontrada." << endl;
}

// Método para verificar fugas (simulación sencilla)
void RedNacional::verificarFugas() {
    cout << "Verificacion de fugas realizada en todas las estaciones. No se encontraron fugas." << endl;
}

// Método para mostrar todas las estaciones de la red
void RedNacional::mostrarEstaciones() {
    cout << "Estaciones en la red nacional:" << endl;
    for (const auto& estacion : estaciones) {
        cout << " - " << estacion << endl;
    }
}
int main() {
    // Crear una red nacional de estaciones de servicio
    RedNacional red;

    // Agregar estaciones de servicio a la red
    red.agregarEstacion("Estacion Norte");
    red.agregarEstacion("Estacion Sur");
    red.agregarEstacion("Estacion Este");

    // Mostrar todas las estaciones
    red.mostrarEstaciones();

    // Verificar fugas en la red
    red.verificarFugas();

    // Eliminar una estación de servicio
    red.eliminarEstacion("Estacion Sur");

    // Mostrar estaciones después de eliminar una
    red.mostrarEstaciones();

    return 0;
}
