#ifndef NODE_H
#define NODE_H

#include "Paciente.h"
#include <string>

using namespace std;

class Node{
    private:
        Paciente* paciente;
        Node* next;
    public:
        Node(Paciente* paciente);
        ~Node();
};

#endif