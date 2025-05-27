#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// Prototipos
int validar(int ri, int rf, const string& msge);
void menu();
int msges();

int main() {
    menu();
    return 0;
}

void menu() {
    int op;
    do {
        op = msges();
        switch (op) {
            case 1:
                cout << "Funciona" << endl;
                system("pause");
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción aún no implementada." << endl;
                system("pause");
        }
    } while (op != 0);
}

int msges() {
    system("CLS");
    cout << "   M  E   N   U" << endl;
    cout << "1. LLENAR VECTOR" << endl;
    cout << "2. LLENAR MATRIZ (ALEATORIAMENTE)" << endl;
    cout << "3. IMPRIMIR VECTOR" << endl;
    cout << "4. IMPRIMIR MATRIZ" << endl;
    cout << "5. ORDENAR VECTOR" << endl;
    cout << "6. BUSCAR VALOR EN EL VECTOR" << endl;
    cout << "0. SALIR" << endl;

    return validar(0, 6, "Escribe una opción");
}

int validar(int ri, int rf, const string& msge) {
    int num;
    string entrada;

    while (true) {
        try {
            cout << msge << " entre " << ri << " y " << rf << ": ";
            getline(cin, entrada);

            // Lanza excepción si hay caracteres no numéricos
            size_t idx;
            num = stoi(entrada, &idx);

            // Validamos que no haya basura después del número
            if (idx != entrada.length()) {
                throw invalid_argument("Entrada con caracteres inválidos.");
            }

            if (num < ri || num > rf) {
                throw out_of_range("Número fuera del rango permitido.");
            }

            return num; // Entrada válida

        } catch (const invalid_argument&) {
            cout << "❌ Error: Ingresa un número válido." << endl;
        } catch (const out_of_range&) {
            cout << "❌ Error: Número fuera de rango." << endl;
        }
    }
}
