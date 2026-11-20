#include<iostream>
#include<string>
#include <stdexcept> 

using namespace std;

class Cliente{
    private:
        string nombre;
        string apellido;
        int nivel_cliente;
        int edad;
        double limite_retiro;
    public:
        Cliente(){}
        // Funciones de nombre
        string capturarNombre(){
            string nombre;
            cout << "Ingresar nombre: ";
            getline(cin >> ws, nombre);
            return nombre;
        }
        void setNombre(string nombre){
            if(nombre.empty() || nombre.length() < 2){
                throw invalid_argument("Ingresa un nombre valido");
            }
            this->nombre = nombre;
        }
        void registrarNombre(){
            bool pendiente = true;
            while(pendiente){
                try{
                    setNombre(capturarNombre());
                    pendiente = false;
                }
                catch(const invalid_argument & e){
                    cout << e.what() << endl;
                    cout << "Intenta nuevamente." << endl;
                }
            }
        }
        // Funciones de apellido
        string capturarApellido(){
            string apellido;
            cout << "Ingresar apellido: ";
            getline(cin >> ws, apellido);
            return apellido;
        }
        void setApellido(string apellido){
            if(apellido.empty() || apellido.length() < 2){
                throw invalid_argument("Ingresa un apellido valido");
            }
            this->apellido = apellido;
        }
        void registrarApellido(){
            bool pendiente = true;
            while(pendiente){
                try{
                    setApellido(capturarApellido());
                    pendiente = false;
                }
                catch(const invalid_argument & e){
                    cout << e.what() << endl;
                    cout << "Intenta nuevamente." << endl;
                }
            }
        }
        // Funciones de edad
        int capturarEdad(){
            int edad;
            cout << "Ingresar edad: ";
            if(!(cin >> edad)){
                throw invalid_argument("Entrada invalida, ingresa un numero");
            }
            return edad;
        }
        void setEdad(int edad){
            if(edad < 18){
                throw invalid_argument("Cliente debe ser mayor de edad");
            }
            this->edad = edad;
        }
        void registrarEdad(){
            bool pendiente = true;
            while(pendiente){
                try{
                    setEdad(capturarEdad());
                    pendiente = false;
                }
                catch(const invalid_argument & e){
                    cout << e.what() << endl;
                    cout << "Intenta nuevamente." << endl;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
            }
        }
        // Funciones de nivel_cliente
        int capturarNivelCliente(){
            int nivel_cliente;
            cout<<"Ingresar nivel de cliente (usar un numero de la lista)" << endl;
            cout<<" | No.  | -- Nivel -- |" <<endl;
            cout<<" |  1   |  Basico     |" <<endl;
            cout<<" |  2   |  Oro        |" <<endl;
            cout<<" |  3   |  Platino    |" <<endl;
            cout<<" |  4   |  VIP        |" <<endl;
            if(!(cin >> nivel_cliente)){
                throw invalid_argument("Entrada invalida, ingresa un numero");
            }
            return nivel_cliente;
        }
        void setNivelCliente(int nivel_cliente){
            if (!(nivel_cliente) || nivel_cliente < 1 || nivel_cliente > 4) {
                throw invalid_argument("Ingresa un no. de nivel de cliente valido");
            }
            this->nivel_cliente = nivel_cliente;
        }
        void registrarNivelCliente(){
            bool pendiente = true;
            while(pendiente){
                try{
                    setNivelCliente(capturarNivelCliente());
                    pendiente = false;
                }
                catch(const invalid_argument & e){
                    cout << e.what() << endl;
                    cout << "Intenta nuevamente." << endl;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
            }
        }
        // Funciones de limite_retiro
        double capturarLimiteRetiro(){
            double limite_retiro;
            cout << "Ingresar limite_retiro: ";
            if(!(cin >> limite_retiro)){
                throw invalid_argument("Entrada invalida, ingresa un numero");
            }
            return limite_retiro;
        }
        void setLimiteRetiro(double limite_retiro){
            if (limite_retiro < 0) {
                throw invalid_argument("Limite de retiro debe ser mayor que cero");
            }
            this->limite_retiro = limite_retiro;
        }
        void registrarLimiteRetiro(){
            bool pendiente = true;
            while(pendiente){
                try{
                    setLimiteRetiro(capturarLimiteRetiro());
                    pendiente = false;
                }
                catch(const invalid_argument & e){
                    cout << e.what() << endl;
                    cout << "Intenta nuevamente." << endl;
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                }
            }
        }

        void capturarDatos(){
            cout<<"\n --- Formulario de registro de cliente ---"<<endl;
            registrarNombre();
            registrarApellido();
            registrarEdad();
            registrarNivelCliente();
            registrarLimiteRetiro();
        };
        
        void mostrarDatos(){
            cout<<"\n --- Ver datos del cliente ---"<<endl;
            cout<<"           Cliente:  " << nombre <<" "<< apellido <<endl;
            cout<<"              Edad:  " << edad <<endl;
            cout<<"             Nivel:  " << nivel_cliente <<endl;
            cout<<"  Limite de retiro: $" << nombre <<" "<< apellido <<endl;
        }
};

int main() {
    const int n = 3;
    Cliente clientes[n];
    char opcion;

    for(int i=0;i < n; i++){
        bool pendiente = true;
        while(pendiente){
            try{
                cout<< "Iniciando registro de cliente "<< (i+1);
                clientes[i].capturarDatos();
                pendiente=false;
            }
            catch(const invalid_argument & e){
                cout<<"\a" << e.what() << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                cout<<"Registro invalido, intenta de nuevo...";
            }
        };
    }

    cout<<"Clientes registrados con exito. Mostrar registros? (S/N)";
    if(opcion =='s' || opcion =='S'){
        for(int i=0; i<n; i++){
            clientes[i].mostrarDatos();
        }
    }
}
