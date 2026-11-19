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
        void capturarDatos(){
            cout<<"\n --- Formulario de registro de cliente ---"<<endl;

            cout<<"Ingresar nombre:";
            getline(cin>> ws, nombre);
            if(nombre.empty() || nombre.length()<2){
                throw invalid_argument("Ingresa un nombre valido");
            }

            cout<<"Ingresar apellido:";
            getline(cin, apellido);
            if(apellido.length()<2){
                throw invalid_argument("Ingresa un apellido valido");
            }

            cout<<"Ingresar edad:";
            if(!(cin >> edad) || edad < 18){
                throw invalid_argument("Cliente debe ser mayor de edad");
            }

            cout<<"Ingresar nivel de cliente (usar un numero de la lista)" << endl;
            cout<<" | No.  | -- Nivel -- |" <<endl;
            cout<<" |  1   |  Basico     |" <<endl;
            cout<<" |  2   |  Oro        |" <<endl;
            cout<<" |  3   |  Platino    |" <<endl;
            cout<<" |  4   |  VIP        |" <<endl;
            if (!(cin >> nivel_cliente) || nivel_cliente < 1 || nivel_cliente > 4) {
                throw invalid_argument("Ingresa un no de nivel de cliente valido");
            }

            cout<<"Ingresar limite de retiro: $";
            if (!(cin >> limite_retiro) || limite_retiro < 0) {
                throw invalid_argument("Limite de retiro debe ser positivo");
            }
        }
};

int main() {
    return 0;
}
