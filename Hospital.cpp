#include "Hospital.h"
#include <iostream>
#include <fstream>
#include <sstream>

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
            deptoActual->mostrarPacientes();
            i++;
            deptoActual = deptoActual->next;
        }
    }

    void Hospital::mostrarHistorial() const{
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

    void Hospital::cargarPacientes(string nombreArchivo){
        ifstream archivo(nombreArchivo);
        if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo " << nombreArchivo << "\n";
        return;
        }

        string linea;
        int agregados = 0;

        while (getline(archivo, linea)) {
        stringstream ss(linea);
        string id, nombre, servicio, edadStr;
        int edad;

        getline(ss, id, ';');
        getline(ss, nombre, ';');
        getline(ss, edadStr, ';');
        getline(ss, servicio);

        if (!id.empty() && !edadStr.empty()) {
            edad = stoi(edadStr); 
            
            Paciente* nuevoPaciente = new Paciente(id, nombre, servicio, edad);
            salaDeEspera.enqueue(nuevoPaciente);
            
            agregados++;
            }
        }
    }

    Hospital::~Hospital() {
    Departamentos* actual = cabezaDepartamentos;
    
    while (actual != nullptr) {
        Departamentos* aBorrar = actual;
        actual = actual->next;
        delete aBorrar; 
    }
}