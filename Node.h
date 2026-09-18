#ifndef NODE_H
#define NODE_H

#include "Paciente.h"
#include <string>

using namespace std;

class Node{
    public:
        Node* next;
        Paciente* paciente;

        Node(Paciente* paciente);
        ~Node();
};

#endif