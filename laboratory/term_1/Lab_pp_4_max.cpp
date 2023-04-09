//Вариант 5
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

std::vector<char> read_file_char() {
    char symbol;
    std::vector<char> array;
    std::ifstream file("input.txt"); // окрываем файл для чтения
    if (file.is_open()) {
        while (file.get(symbol)) {
            array.push_back(symbol);
        }
    }
    file.close();
    return array;
}

std::vector<std::string> read_file_str() {
    std::string str;
    std::vector<std::string> array;
    std::ifstream file("input.txt"); // окрываем файл для чтения
    if (file.is_open()) {
        while (getline(file, str)) {
            array.push_back(str);
        }
    }
    file.close();
    return array;
}

std::vector<char> sort_string(std::vector<char> array) {
    std::vector<char> final_array;
    bool flag = 0;
    for (char i = '0'; i <= 'Z'; ++i) {
        flag = 0;
        for (int j = 0; j < array.size(); ++j) {
            if (array[j] == '\n') {
                flag = 0;
            } else if (flag == 1) {
                final_array.push_back(array[j]);
            } else if ((j == 0 && toupper(array[j]) == i) || (array[j - 1] == '\n' && toupper(array[j]) == i)) {
                flag = 1;
                if (!final_array.empty())
                    final_array.push_back('\n');
                final_array.push_back(array[j]);
            }
        }
    }
    return final_array;
}

std::vector<std::string> sort_string(std::vector<std::string> array) {
    std::vector<std::string> final_array;
    for (char i = '0'; i <= 'Z'; ++i) {
        for (int j = 0; j < array.size(); ++j) {
            if (toupper(array[j][0]) == i)
                final_array.push_back(array[j]);
        }
    }
    return final_array;
}

void record_file(std::vector<char> array) {
    std::ofstream file("output.txt");
    for (char i: array)
        file.put(i);
    file.close();
}

void record_file(std::vector<std::string> array) {
    std::ofstream file("output.txt");
    for (std::string i: array)
        file << i<<std::endl;
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

            std::vector<char> array;
            std::vector<char> final_array;
            array = read_file_char();
            final_array = sort_string(array);
            record_file(final_array);

            auto this_char = high_resolution_clock::now();
            time_char += this_char - start_char;
        }
        for (int j = 0; j < 10; ++j) {
            auto start_str = high_resolution_clock::now();

            std::vector<std::string> array;
            std::vector<std::string> final_array;
            array = read_file_str();
            final_array = sort_string(array);
            record_file(final_array);

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