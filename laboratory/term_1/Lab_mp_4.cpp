#include <iostream>
#include <fstream>
#include <vector>
#include <string> //подключена для правильной работы getline() при зацикливании программы.

std::vector<char> read_file_char() {
    char symbol;
    std::vector<char> array;
    std::ifstream file("input.txt"); // окрываем файл для чтения
    if (file.is_open()) {
        while (file.get(symbol) && symbol != '\n') {
            if (isalpha(symbol)) array.push_back(tolower(symbol));
        }
    }
    file.close();
    return array;
}

bool is_palindrom_char(std::vector<char> array) {
    int size = array.size();
    int stop = (size % 2 + size / 2);
    bool flag = true;
    for (int i = 0; i < stop; ++i) {
        flag *= (array[i] == array[size - 1 - i]);
    }
    return flag;
}

void record_file(bool palindrom) {
    std::ofstream file("output.txt");
    if (palindrom == 1) file << "The string is a palindrome" << std::endl;
    else file << "The string is not a palindrome" << std::endl;
    file.close();
}

int main() {
    std::string ex = "";
    while (ex != "Exit") {
        std::vector<char> array = read_file_char();
        bool palindrom = is_palindrom_char(array);
        record_file(palindrom);
        std::cout << "The result of the program was recorded in the file." << std::endl;
        std::cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}