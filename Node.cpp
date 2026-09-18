#include "Node.h"

Node::Node(Paciente* paciente){
    this->paciente = paciente;
    this->next = nullptr;
}

Node::~Node() {delete paciente;}