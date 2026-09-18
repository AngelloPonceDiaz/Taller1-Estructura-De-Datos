#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include "Node.h"

class Queue{

private:
    Node* front;
    Node* rear;

public:
    Queue();
    void enqueue(Paciente* paciente);
    Paciente* dequeue();
    bool isEmpty() const;
    void mostrarPacientes() const;

};
#endif
