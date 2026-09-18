
#include "Paciente.h"

using namespace std;

Paciente::Paciente(string id, string nombre, string servicio, int edad) : Persona(nombre, edad){
    this->id = id;
    this->servicio = servicio;
}

string Paciente::getId() const{
    return id;
}

string Paciente::getServicio() const{
    return servicio;
};