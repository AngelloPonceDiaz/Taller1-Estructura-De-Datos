#include "Departamentos.h"
#include <string>

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