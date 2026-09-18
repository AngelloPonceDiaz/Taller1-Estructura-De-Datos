#ifndef STACK_H
#define STACK_H
#include <string>

class StackNodo{
    public:
    std::string nombre;
    int edad;
    std::string servicio;
    StackNodo* next;

    StackNodo(std::string nombre, int edad, std::string servicio);
};

class Stack{
    private:
        StackNodo* top;
    public:
        Stack();
        StackNodo* getStackNodo();
        void push(std::string nombre, int edad, std::string servicio);
        void mostrarHistorial() const;
};

#endif