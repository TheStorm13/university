#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>


std::string read_file_str() {
    std::string str;
    std::ifstream file("input.txt"); // окрываем файл для чтения
    if (file.is_open()) {
        getline(file, str);
    }
    file.close();
    return str;
}
// Удаляем лишние символы из строки
std::string true_string(std::string str) {
    for (int i = 0; i < str.size(); ++i) {
        while ((isalpha(str[i]))==0) str.erase(i, 1);
        str[i] = tolower(str[i]);
    }
    return str;
}

bool is_palindrom_str(std::string str) {
    bool flag = true;
    int size = str.size();
    int stop = (size % 2 + size / 2);
    for (int i = 0; i < stop; ++i) {
        flag *= (str[i] == str[size - 1 - i]);
    }
    return flag;
}

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
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    std::string ex = "";
    while (ex != "Exit") {
        duration<double, std::milli> time_char = high_resolution_clock::duration::zero();
        duration<double, std::milli> time_str = high_resolution_clock::duration::zero();

        for (int i = 0; i < 10; ++i) {
            auto start_char = high_resolution_clock::now();

            std::vector<char> array = read_file_char();
            bool palindrom_char = is_palindrom_char(array);
            record_file(palindrom_char);

            auto this_char = high_resolution_clock::now();
            time_char += this_char - start_char;
        }
        for (int j = 0; j < 10; ++j) {
            auto start_str = high_resolution_clock::now();

            std::string str = read_file_str();
            str = true_string(str);
            bool palindrom_str = is_palindrom_str(str);
            record_file(palindrom_str);

            auto this_str = high_resolution_clock::now();
            time_str += this_str - start_str;
        }

        std::cout << "Strings are " << (time_char.count() / 10.0) / (time_str.count() / 10.0) << " times faster"
                  << std::endl;

        std::cout << "The result of the program was recorded in the file." << std::endl;
        std::cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}