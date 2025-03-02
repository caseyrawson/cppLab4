#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "LinkedList.h"
#include <vector>

//test_list if properly constructed
bool verify_linked_list(Node* test_list_root, const std::vector <int> &expected) {
    Node* current = test_list_root;
    for (size_t i = 0; i < expected.size(); i++) {
        if (!current || current->data != expected[i]) {
            return false;
        }
        current = current->next;
    }
    return (current == nullptr); //make sure it is last element
}

TEST_CASE("Test building list") {
    std::vector <int> test_list = {1, 2, 3, 4, 5};
    Node* test_list_root = build_linked_list(test_list);
    CHECK(verify_linked_list(test_list_root, test_list));
    delete_entire_linked_list(test_list_root);
}

TEST_CASE("Test getting a value") {
    std::vector <int> test_list = {10, 20, 30, 40, 50};
    Node* test_list_root = build_linked_list(test_list);

    CHECK(get_linked_list_data_item_value(test_list_root, 1) == 10);
    CHECK(get_linked_list_data_item_value(test_list_root, 3) == 30);
    CHECK(get_linked_list_data_item_value(test_list_root, 6) == -1); //Out of range
    CHECK(get_linked_list_data_item_value(test_list_root, 0) == -1); //too low

    delete_entire_linked_list(test_list_root);
}

TEST_CASE("Test deleting an element") {
    std::vector <int> test_list = {100, 200, 300, 400, 500};
    Node* test_list_root = build_linked_list(test_list);

    //delete 300.
    test_list_root = delete_list_element(test_list_root, 3);
    std::vector <int> expected1 = {100, 200, 400, 500};
    CHECK(verify_linked_list(test_list_root, expected1));

    //delete 100
    test_list_root = delete_list_element(test_list_root, 1);
    std::vector <int> expected2 = {200, 400, 500};
    CHECK(verify_linked_list(test_list_root, expected2));

    //delete 500
    test_list_root = delete_list_element(test_list_root, 3);
    std::vector <int> expected3 = {200, 400};
    CHECK(verify_linked_list(test_list_root, expected3));

    delete_entire_linked_list(test_list_root);
}

TEST_CASE("Test move constructor") {
    std::vector<int> test_list = {4, 5, 6};
    Node* first = build_linked_list(test_list);
    Node second(std::move(*first)); //move first to second

    CHECK(verify_linked_list(&second, test_list)); //check second matches list
    CHECK(first->next == nullptr);
    delete first;
}

TEST_CASE("Test move assignment operator") {
    std::vector<int> test_list = {8, 9, 15};
    Node* first = build_linked_list(test_list);
    Node second(0); //dummy value
    second = std::move(*first); //transfer first to second

    CHECK(verify_linked_list(&second, test_list));
    CHECK(first->next == nullptr);
    delete first;
}
