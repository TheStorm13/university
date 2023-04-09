#include <iostream>
#include <fstream>
#include <iomanip>

class List;

class Node {
    int value;
    Node *next = nullptr;
    Node *previous = nullptr;
    friend List;
};

class List {
    Node *head;
    int size;
    bool mode;

    void push_back(int value) {
//        Node *now = head;
//        while (now->next != nullptr)
//            now = now->next;
//        now->next = new Node;
//        (now->next)->previous = now;
//        (now->next)->value = value;
//Var2
        Node *now = new Node;
        if (head)
            head->previous = now;
        now->next = head;
        now->value = value;
        head = now;
    }

    void swap(Node *first, Node *second) {
        Node *f_next = first->next;
        Node *s_next = second->next;
        Node *f_previous = first->previous;
        Node *s_previous = second->previous;

        if (first == head)
            head = second;

        if (first->next == second) {
            second->next = first;
            first->previous = second;
        } else {
            first->previous = s_previous;
            s_previous->next = first;
            second->next = f_next;
            f_next->previous = second;

        }
        first->next = s_next;
        if (s_next)
            s_next->previous = first;

        second->previous = f_previous;
        if (f_previous)
            f_previous->next = second;
    }

    Node *max(Node *first, Node *second, Node *third) {
        return (first->value > second->value) ?
               ((first->value > third->value) ? first : third) : ((second->value > third->value) ? second : third);
    }

    void SelectionSort() {
        Node *now;
        Node *check;
        int i, j;
        for (i = 0; i < size; ++i) {
            now = check = head;
            for (j = 1; j < size - i; ++j) {
                check = check->next;
                if (check->value > now->value)
                    now = check;
            }
            if (check->value < now->value)
                swap(now, check);
        }
    }

    void heapify(int border) {
        Node *pointParent = head;
        Node *pointSun = pointParent->next->next;
        Node *Parent;
        Node *Sun;


        for (int i = 3; i < border; ++i) {
            if (i & 1)
                pointParent = pointParent->next;
            pointSun = pointSun->next;
        }
        while (Parent) {
            print();
            Parent = pointParent;
            Sun = pointSun;
            std::cout<<Parent->value<<" "<<Sun->value<<"    ";
            pointParent = pointParent->previous;
            pointSun = pointSun->previous->previous;
            std::cout<<pointParent->value<<" "<<pointSun->value<<"    ";
            swap(Parent, max(Parent, Sun,
                             (border & 1 ? Sun->previous : (Sun->next ? Sun->next : Sun))));

        }
        Node *now = head;
        while (now->next) {
            now = now->next;
        }
        swap(head, now);
        std::cout << std::endl;
    }

    void HeapSort() {
        for (int i = size; i > 0; --i) {
            heapify(i);
        }

    }

public:
    List() {
        head = nullptr;
        size = 0;
    }

    List(int value) {
        head = new Node;
        head->value = value;
        size = 1;
    }

    void input() {
        int num;

        std::ifstream infile;
        infile.open("input.txt");

        if (infile.is_open()) {
            infile >> mode;
            while (infile >> num) {
                ++size;
                push_back(num);
            }
        }
        infile.close();
    }

    void output() {
        std::ofstream outfile;
        outfile.open("output.txt");

        if (outfile.is_open()) {
            outfile << size << " ";

            Node *now = head;
            while (now != nullptr) {
                outfile << now->value << " ";
                now = now->next;
            }
        }
        outfile.close();
    }

    void print() {
        Node *now = head;
        while (now != nullptr) {
            std::cout << now->value << " ";
            now = now->next;
        }
        std::cout << std::endl;
    }

    void sort() {
        mode ? HeapSort() : SelectionSort();
    }

    ~List() {
        if (head) {

            Node *now;
            Node *second = now = head;
            do {
                second = second->next;
                delete now;
                now = second;

            } while (now != nullptr);
        }
    }
};


int main() {
    List list;

    list.input();
    list.sort();
    list.output();

    return 0;
}