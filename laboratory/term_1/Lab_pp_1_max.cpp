#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Проверка на целое число
int check_integer() {
    std::string str = "";
    bool state = true;
    int  number;
    std::size_t pos{};

    std::cout << "Enter the size of the array: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size() || number < 2) {
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

// Добавление элемента в массив
void add_list(string list[], int size, int count) {
    while (count < (size)) {
        string element;
        cout << "Enter an element of the array: ";
        getline(cin, element);
        // Если строка не содержит пробелов, то мы инициализируем элемент как эту строку
        if (element.find_first_of(" ") == -1) {
            list[count] = element;
            ++count;
        } else {
            cout << "You entered the wrong value. Enter it again: " << endl;
            return add_list(list, size, count);
            // Тут можно обрезать строку и добавить элементы из нее
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string ex = "";
    while (ex != "Exit") {
        int count = 0;
        int size1 = 0;
        cout << "Enter the number of elements in the array: ";
        size1 = check_integer(); // Получение от пользователя размера массива
        string *list1 = new string[size1]; // Выделение памяти для массива

        int size2 = 0;
        cout << "Enter the number of elements in the subarray: ";
        size2 = check_integer(); // Получение от пользователя размера массива
        string *list2 = new string[size1]; // Выделение памяти для массива

        int *list3 = new int[size2]; // Выделение памяти для массива
        cout << "Array" << endl;
        add_list(list1, size1, count);
        cout << "Subarray" << endl;
        add_list(list2, size2, count);

        cout << "Subarray element" << " " << "Number of occurrences in the array" << endl;
        // Считаем количесво вхожений элементов подмассива в массив
        for (int a = 0; a < size2; ++a) {
            int b = 0;
            list3[a] = 0;
            for (int b = 0; b < size1; ++b) {
                if (list2[a] == list1[b]) {
                    ++list3[a];
                }
            }
            cout << setw(18) << list2[a] << "     " << list3[a] << endl;
        }

        cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
        delete[] list1; // Очистка памяти
        delete[] list2;
        delete[] list3;
    }
    return 0;
}

