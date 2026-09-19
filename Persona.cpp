#include "Persona.h"
#include <string>
using namespace std;

class Persona{
    protected:
    string nombre;
    int edad;

    public:

    Persona(string nombre, int edad){
        this->nombre = nombre;
        this->edad = edad;
    }

    string getNombre(){return nombre;}

    int getEdad(){return edad;}

    virtual ~Persona() {}
};
