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

void Stack::mostrarHistorial() const{
    if(top == nullptr){
        cout << "El historial está completamente vacío";
        return;
    }

    StackNodo* actual = top;
    cout << "====--- HISTORIAL ---====" << endl;
    while(actual != nullptr){

        string nombre = actual->nombre;
        int edad = actual->edad;
        string servicio = actual->servicio;

        cout << "Nombre: " << nombre << " || Edad: " << edad << " || Servicio: " << servicio << endl;

        actual = actual->next;
    }
}