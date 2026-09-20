#include "Queue.h"
#include <stdexcept>
#include <iostream>

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

void Queue::enqueue(Paciente* paciente) {
    Node* nodo = new Node(paciente);
    
    if (front == nullptr) {
        front = nodo;
        rear = nodo;
    } else {
        rear->next = nodo;
        rear = nodo;
    }
}

Paciente* Queue::dequeue(){
    if(front == nullptr){
        throw out_of_range("La cola está vacía");
    }

    Node* actual = front;
    Paciente* pacienteOut = actual->paciente;
    front = front->next;

    if(front == nullptr){
        rear = nullptr;
    }
    actual->paciente = nullptr;
    delete actual;
    return pacienteOut;
}

bool Queue::isEmpty() const{
    return front == nullptr;
}

void Queue::mostrarPacientes() const{
    if(front == nullptr){
        cout << "La lista de pacientes está vacía!";
        return;
    }
    cout << "=== PACIENTES EN ESPERA ===";
    Node* actual = front;

    int i = 1;
    while(actual != nullptr){

        cout << "\n" << i << ". " << actual->paciente->getId() << " - " << actual->paciente->getNombre();
        actual = actual->next;
        i++;
    }

}