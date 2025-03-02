#include "LinkedList.h"
#include <iostream>

//build list
Node* build_linked_list(const std::vector <int> &values) {
    if (values.empty())
        return nullptr;
    Node* root = new Node(values[0]);
    Node* current = root;
    for (size_t i=1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return root;
}

void print_linked_list(const Node* root) {
    const Node* current = root;
    while (current) {
        std::cout << current->data;
        if (current->next) {
            std::cout << " ";
        current = current->next;
        }
    }
    std::cout << std::endl;
}

void delete_entire_linked_list(Node* root) {
    delete root; //calls delete on root, which then deletes every item after it
}

int get_linked_list_data_item_value(Node * root, int node_number) {
    if (node_number < 1) {return -1;}
    const Node* current = root;
    int i = 1;
    while (i < node_number) {
        current = current->next;
        i++;
        if (current->next == nullptr) {return -1;}
    }
    return current->data;
}

Node* delete_list_element (Node* root, int node_number) {
    if (node_number == 1) {
        Node* new_root = root->next;
        root->next = nullptr; //so that all the others are not deleted
        delete root;
        return new_root;
    }
    Node* current = root;
    int i = 1;
    while (current && i < node_number - 1) { //stop at node before node to be deleted
        current = current->next;
        i++;
    }
    if (current && current->next) {
        Node* goner = current->next;
        current->next = goner->next;
        goner->next = nullptr;
        delete goner;
    }
    return root;
}