#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string get_file() {
    std::string name_file;
    bool state = true;

    std::cout << "Enter the name file: ";

    while (state) {
        getline(std::cin, name_file);

        std::ifstream file;
        file.open(name_file);

        if (!file || name_file.find(".txt") == -1 || name_file.empty()) {
            std::cout << "You entered the wrong value. Enter it again: " << std::endl;
        } else
            state = false;
    }

    return name_file;
}

std::vector<char> read_file(std::string name_file, std::vector<char> array) {
    char symbol;

    std::ifstream file(name_file); // окрываем файл для чтения

    if (file.is_open()) {
        while (file.get(symbol))
            array.push_back(symbol);
    }
    file.close();

    return array;
}

std::vector<char> string_conversion(std::vector<char> array) {
    for (int i = 0; i < array.size(); ++i) {

        if (isalpha(array[i])) {
            if (isalpha(array[i - 1]) == false || i == 0)
                array[i] = toupper(array[i]);
            else
                array[i] = tolower(array[i]);
        }
    }
    return array;
}

void record_file(std::string name_file, std::vector<char> array) {
    std::ofstream file(name_file);

    if (file.is_open()) {
        for (char symbol: array)
            file << symbol;
    }
    file.close();

    std::cout << "The result of the program was recorded in the file." << std::endl;
}

int main() {
    std::vector<char> array;
    std::string name_file = get_file();

    array = read_file(name_file, array);
    array = string_conversion(array);
    record_file(name_file, array);

    return 0;
}