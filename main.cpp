#include <iostream>
#include "Hospital.h"

using namespace std;

int main() {
    Hospital miHospital;
    
    miHospital.agregarDepartamento("Urgencias");
    miHospital.agregarDepartamento("Pediatria");
    miHospital.agregarDepartamento("Cardiologia");
    miHospital.agregarDepartamento("Traumatologia");

    cout << "=== INICIANDO SISTEMA DEL PAPU-HOSPITAL ===\n";
    
    miHospital.cargarPacientes("pacientes.txt");

    int opcion;
    do {
        cout << "\n========== MENU PRINCIPAL ==========\n";
        cout << "1. Mostrar pacientes en espera\n";
        cout << "2. Atender pacientes\n";
        cout << "3. Mostrar pacientes en departamentos\n";
        cout << "4. Ver historial de atenciones\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\n";
                miHospital.mostrarSalaDeEspera();
                break;
                
            case 2: {
                int cantidad;
                cout << "\n¿Cuantos pacientes deseas atender en esta ronda?: ";
                cin >> cantidad;
                miHospital.atenderSiguientePaciente(cantidad);
                break;
            }
                
            case 3:
                cout << "\n=== ESTADO DE LOS DEPARTAMENTOS ===\n";
                miHospital.mostrarTodosLosDepartamentos();
                break;
                
            case 4:
                cout << "\n";
                miHospital.mostrarHistorial();
                break;
                
            case 5:
                cout << "\nCerrando el hospital. ¡Nos vemos!\n";
                break;
                
            default:
                cout << "\nOpción no válida. Intenta de nuevo.\n";
        }
        
    } while(opcion != 5);

    return 0;
}