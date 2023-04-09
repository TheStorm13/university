#include <iostream>
#include <vector>

// запрограммировать все методы, конструкторы и диструкторы
class List;

class Node {
    int value;
    Node *next;
public:
    Node(int value) {
        this->value = value;
    }

    friend List;
};

class List {
private:
    Node *head;
    int size;

    void swap() {


    }

public:
    List(int value) {
        size = 1;
        head = new Node(value);
    };

    Node push_front(Node) {
    }

    Node push_back(Node) {
    }

    void sort1() {
        for (Node *i = head; i->next != head; i = i->next) {
            for (Node *j = head; j->next->next != head; j = j->next) {
                if (j->value > j->next->value)
                    swap(j, j->next);
            }
        }
    }

/*
 * head->next=p;
 * 
 */
    int pop_front() {
        int value = head->value;
        this->head = head->next;
        delete[] head;
        return value;
    }

    int pop_back() {
    }

    int get() {
    }

    int getSize() {
    }

    // =
    // ==
    // <<
    // >>
    // +
    // У Node есть друг List
};

class PList {


};

int main() {


    return 0;
}

