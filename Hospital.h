#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <string>
#include "Departamentos.h"
#include "Queue.h"
#include "Stack.h"

class Hospital {
private:

    Departamentos* cabezaDepartamentos; 
    
    Queue salaDeEspera;        
    Stack historialAtenciones; 

public:
    Hospital();
    
    void agregarDepartamento(std::string nombre);
    void atenderSiguientePaciente(int cantidad); 
    void mostrarTodosLosDepartamentos() const;
    void mostrarHistorial() const;
    void mostrarSalaDeEspera() const;
    void cargarPacientes(string nombreArchivo);
    ~Hospital();
};

#endif