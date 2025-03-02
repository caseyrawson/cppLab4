#include "Node.h"

//making constructor
Node::Node(int data, Node* next) {
    this->data = data; 
    this->next = next;
}

//deep copy constructor
Node::Node(const Node& point) {
    data = point.data;
    next = nullptr;
    if (point.next) {
        next = new Node(*point.next); //if next, call function again
    }
}

//move constructor
Node::Node(Node&& other) noexcept {
    data = other.data;
    next = other.next;
    other.next = nullptr; //set original ptr to null
}

//move assignment
Node& Node::operator=(Node&& other) noexcept {
    if (this != &other) {
        delete next; //free current node chain
        data = other.data;
        next = other.next;
        other.next = nullptr; //copy and set orig to null
    }
    return *this;
}


//making destructor
Node::~Node() {
    delete next;
}
