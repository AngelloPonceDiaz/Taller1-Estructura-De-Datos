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

    }