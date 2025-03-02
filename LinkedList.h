#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include "Node.h"

//using vector for better access
Node* build_linked_list(const std::vector<int> &values);

void print_linked_list(const Node* root);

void delete_entire_linked_list(Node* root);

int get_linked_list_data_item_value(Node* root, int node_number);

Node* delete_list_element (Node* root, int node_number);

#endif