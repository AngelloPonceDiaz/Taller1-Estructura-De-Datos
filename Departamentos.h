#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include "Node.h"

class Departamentos{
    public:
    std::string nombre;
    Node* cabezaPaciente;
    Departamentos* next;

    Departamentos(std::string nombre);
    void agregarPaciente(Paciente* paciente);
    void mostrarPacientes() const;
};

#endif