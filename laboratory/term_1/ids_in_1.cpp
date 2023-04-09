#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> read_file(std::vector<std::string> array) {
    std::string alphabet = " ,";
    std::string str;
    std::ifstream file("INPUT.TXT"); // окрываем файл для чтения
    if (file.is_open()) {
        for (int i = 0; i < 9; ++i) {
            getline(file, str);
            alphabet += str + ',';
        }
        getline(file, str);
    }
    array.push_back(alphabet);
    array.push_back(str);
    file.close();
    return array;
}

int string_count(std::vector<std::string> array) {
    int count = 0;
    int upper = 1;
    int former_button = 0;
    int now_button = 0;
    std::string alphabet = array[0];
    std::string str = array[1];//"Hello!  Hi!";//

    for (int i = 0; i < str.size(); ++i) {
        char symbol_string = str[i];
        int touch = 1;

        for (int j = 0; touch != 0; ++j) {
            char symbol_alphabet = alphabet[j];

            if (symbol_alphabet == ',') {
                touch = 1;
                now_button += 1;
            } else if (symbol_alphabet == tolower(symbol_string)) {
                if (std::isalpha(symbol_string) == false && symbol_string != ' ')
                    upper==2?upper=2:upper = 1;
                if (upper && std::isalpha(symbol_string) && std::isupper(symbol_string) == false) {
                    touch += 1;
                    upper = 0;
                } else if (upper == 0 && std::isalpha(symbol_string) && std::isupper(symbol_string) == true) {
                    touch += 1;
                    upper = 2;
                }
                if (upper == 1 && std::isalpha(symbol_string) && std::isupper(symbol_string) == true)
                    upper = 0;
                if (i != 0 && former_button == now_button && symbol_string!=' ')
                    touch += 1;
                former_button = now_button;
                std::cout << symbol_string << " " << touch << std::endl;
                count += touch;
                touch = 0;
                now_button = 0;
            } else touch += 1;
        }
    }
    std::cout << alphabet << std::endl << str << std::endl;
    return count;
}

void record_file(int count) {
    std::ofstream file("OUTPUT.TXT");
    if (file.is_open()) {
        file << count;
    }
    file.close();
    std::cout << "The result of the program was recorded in the file." << std::endl;
}

int main() {
    std::vector<std::string> array;
    array = read_file(array);
    int count = string_count(array);
    record_file(count);
    return 0;
}