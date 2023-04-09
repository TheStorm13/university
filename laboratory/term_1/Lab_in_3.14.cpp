#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>

int get_size() {
    std::string str = "";
    bool state = true;
    int number;
    std::size_t pos{};

    std::cout << "Enter the size of the sequence: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size() || number < 2) {
                //std::cerr << "1\n";
                throw std::invalid_argument("Argument is invalid\n");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

int get_element() {
    std::string str = "";
    bool state = true;
    double number;
    std::size_t pos{};

    std::cout << "Enter the element of the sequence: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size()) {
                throw std::invalid_argument("Argument is invalid. ");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

int random(int size) {
    srand(time(0));
    int random = rand() % size;
    return random;
}

std::vector<int> array_filling(int size, std::vector<int> array) {
    for (int i = 0; i < size; ++i)
        array.push_back(get_element());
    return array;
}

int not_number_in(std::vector<int> array) {
    std::vector<int> buffer;
    std::sort(array.begin(), array.end());
    int medium = 0;

    for (int i = array[0]; i <= array.back(); ++i) {
        if (std::binary_search(array.begin(), array.end(), i))
            medium += i;
        else
            buffer.push_back(i);
    }

    medium /= array.size();

    for (int i = array.front() - medium; i < array.front(); ++i)
        buffer.push_back(i);

    for (int i = array.back(); i < +array.back() + medium; ++i)
        buffer.push_back(i);
    return buffer[random(buffer.size())];
}

int main() {
    std::string ex = "";

    while (ex != "Exit") {
        std::vector<int> array;

        int size = get_size();
        array = array_filling(size, array);
        int random_number_not_in = not_number_in(array);

        std::cout << "Result: " << random_number_not_in << std::endl;

        std::cout << "To exit, type 'Exit'. If you want to continue, type anything else. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}