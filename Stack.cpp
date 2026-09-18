#include "Stack.h"
#include <iostream>

using namespace std;

StackNodo::StackNodo(string nombre, int edad, string servicio) {
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
    this->next = nullptr;
}


Stack::Stack() {
    this->top = nullptr;
}

void Stack::push(string nombre, int edad, string servicio) {
    StackNodo* nodo = new StackNodo(nombre,edad,servicio);
    nodo->next = top;
    top = nodo;
}