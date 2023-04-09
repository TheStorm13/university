//Вариант 5
#include <iostream>
#include <fstream>
#include <vector>

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

std::vector<char> sort_string(std::vector<char> array) {
    std::vector<char> final_array;
    bool flag = 0;
    for (char i = '0'; i <= 'Z'; ++i) {
        flag=0;
        for (int j=0; j < array.size(); ++j) {
            if (array[j] == '\n') {
                flag = 0;
            } else if (flag == 1) {
                final_array.push_back(array[j]);
            }else if ((j == 0 && toupper(array[j]) == i) || (array[j - 1] == '\n' && toupper(array[j]) == i)) {
                flag = 1;
                if (!final_array.empty())
                    final_array.push_back('\n');
                final_array.push_back(array[j]);
            }
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

int main() {
    std::string ex = "";
    while (ex != "Exit") {
        std::vector<char> array;
        std::vector<char> final_array;
        array= read_file_char();
        final_array= sort_string(array);
        record_file(final_array);
        std::cout << "The result of the program was recorded in the file." << std::endl;
        std::cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}
//http://cppstudio.com/post/437/