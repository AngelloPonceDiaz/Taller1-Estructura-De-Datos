#include "Departamentos.h"
#include <string>
#include <iostream>

Departamentos::Departamentos(string nombre){
    this->nombre = nombre;
    cabezaPaciente = nullptr;
    next = nullptr;
}

void Departamentos::agregarPaciente(Paciente* paciente){
    Node* nodo = new Node(paciente);
    nodo->next = cabezaPaciente;
    cabezaPaciente = nodo;
}

void Departamentos::mostrarPacientes() const {
    int cantPaciente = 0;
    if (cabezaPaciente == nullptr) {
        cout << "  No hay pacientes en " << nombre << ".\n";
        return;
    }

    Node* actual = cabezaPaciente;
    Node* aux = cabezaPaciente;

    while(aux != nullptr){cantPaciente++; aux = aux->next;}

    cout << " ===== Pacientes en " << nombre << ": "<< cantPaciente << " ===== ";
    while(actual != nullptr){
        Paciente* p = actual->paciente;

        cout << p->getNombre() << " (" << p->getEdad() << ")\n";
        actual = actual->next;
    }
}