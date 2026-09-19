#include "Hospital.h"
#include <iostream>

using namespace std;

    Hospital::Hospital(){
        this->cabezaDepartamentos = nullptr;
    }

    void Hospital::agregarDepartamento(string nombre) {
    Departamentos* nuevoDepto = new Departamentos(nombre);
    
    nuevoDepto->next = cabezaDepartamentos;
    cabezaDepartamentos = nuevoDepto;
    }

    void Hospital::mostrarTodosLosDepartamentos() const{
        
        Departamentos* deptoActual = cabezaDepartamentos;
        int i = 1;
        while(deptoActual != nullptr){
            cout << i << ") Departamento de " << deptoActual->nombre << endl;
            deptoActual->mostrarPacientes();
            i++;
            deptoActual = deptoActual->next;
        }
    }

    void Hospital::mostrarHistorial() const{
        cout << "====== HISTORIAL DEL PAPU-HOSPITAL =======";
        historialAtenciones.mostrarHistorial();
    }

    void Hospital::atenderSiguientePaciente(int cantidad){
        for(int i = 0 ; i < cantidad ; i++){

            Paciente* pacienteActual = salaDeEspera.dequeue();
            Departamentos* deptoActual = cabezaDepartamentos;

            if(pacienteActual == nullptr){cout << "La lista de espera está vacía!";return;}

            string nombreP = pacienteActual->getNombre();
            int edadP = pacienteActual->getEdad();
            string servicioP = pacienteActual->getServicio();

            cout << "Atendiendo a " << nombreP << " de " << edadP << " años, sala de " << servicioP << "\n";

            while(deptoActual != nullptr){
                if(deptoActual->nombre == pacienteActual->getServicio()){
                    deptoActual->agregarPaciente(pacienteActual);
                    break;
                }

                deptoActual = deptoActual->next;
            }historialAtenciones.push(nombreP, edadP, servicioP);
        }
        cout << "\nProceso de atencion finalizado.\n";
    }

    void Hospital::mostrarSalaDeEspera() const{
        salaDeEspera.mostrarPacientes();
    }
