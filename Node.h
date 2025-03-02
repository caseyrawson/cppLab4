#ifndef NODE_H
#define NODE_H
#include <iostream>

struct Node{
    int data;
    struct Node* next;

    //constructor
    Node(int data = 0, Node* next = nullptr);

    //copy constructor
    Node(const Node &point);

    //move constructor
    Node(Node&& other) noexcept;

    //move assignment
    Node& operator=(Node&& other) noexcept;

    //destructor
    ~Node();
};

#endif