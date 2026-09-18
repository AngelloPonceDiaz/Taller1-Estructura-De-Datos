#ifndef PACIENTE_H
#define PACIENTE_H

#include <string>
#include "Persona.h"

using namespace std;

class Paciente : public Persona {
private:
    string id;
    string servicio;

public:
    Paciente(string id, string nombre, string servicio, int edad);

    string getId() const;
    string getServicio() const;
};

#endif