#include<iostream>
#include<vector>

using namespace std;
class Surtidor;  // Declaramos que existe una clase Surtidor
class Venta; 
class redNacional{
    private://atributos
        vector<string> estaciones;
    public://metodos
        
        void mostrarRedenacional() const;
        void agregarEstacion(string nombre);
        void eliminarEstacion(string nombre);
        
};

class EstacionServicio{
    private:
        string nombre,codigo, region;
        float precioCorriente,precioDiesel,precioExtra;
        vector<Surtidor>surtidores;
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
        vector <Venta>ventas;
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

void redNacional::agregarEstacion(string nombre) {
    estaciones.push_back(nombre);
    cout << "Estacion " << nombre << " agregada a la red." << endl;
}

void redNacional::mostrarRedenacional() const {
    if (estaciones.empty()) {
        cout << "No hay estaciones registradas en la red." << endl;
    } else {
        cout << "Estaciones en la Red Nacional: " << endl;
        for (const auto& estacion : estaciones) {
            cout << "- " << estacion << endl;
        }
    }
}

void redNacional::eliminarEstacion(string nombre) {
    for (auto it = estaciones.begin(); it != estaciones.end(); ++it) {
        if (*it == nombre) {
            cout << "Se ha eliminado la estacion: " << nombre << endl;
            estaciones.erase(it);
            return;
        }
    }
    cout << "No se encontró ninguna estación con el nombre: " << nombre << endl;
}