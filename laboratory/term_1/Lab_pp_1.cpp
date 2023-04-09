#include <iostream>
#include <iomanip>

using namespace std;

// Проверка на целое число
int check_integer() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of("1234567890") != -1) {
        cout << "Вы ввели неправильное значение. Введите его еще раз:" << endl;
        return check_integer();
    } else {
        int str_i = stoi(str1);// Преобразование строки в int
        // Проверка на положительное число
        if (str_i < 2) {
            cout << "Вы ввели слишком маленькое значение. Введите его еще раз:" << endl;
            return check_integer();
        } else {
            return str_i;
        }
    }
}

// Добавление элемента в массив
void add_list(string list[], int size, int count) {
    while (count < (size)) {
        string element;
        cout << "Введите элемент массива: ";
        getline(cin, element);
        // Если строка не содержит пробелов, то мы инициализируем элемент как эту строку
        if (element.find_first_of(" ") == -1) {
            list[count] = element;
            ++count;
        } else {
            cout << "Вы ввели неправильное значение. Введите его еще раз:" << endl;
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
        cout << "Введите количество элементов в массиве: ";
        size1 = check_integer(); // Получение от пользователя размера массива
        string *list1 = new string[size1]; // Выделение памяти для массива

        int size2 = 0;
        cout << "Введите количество элементов в подмассиве: ";
        size2 = check_integer(); // Получение от пользователя размера массива
        string *list2 = new string[size1]; // Выделение памяти для массива

        int *list3 = new int[size2]; // Выделение памяти для массива
        cout << "Массив" << endl;
        add_list(list1, size1, count);
        cout << "Подмассив" << endl;
        add_list(list2, size2, count);

        cout << "Элемент подмассива" << "     " << "Кол-во вхождений в массив" << endl;
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

        cout << "Для выхода введите 'Exit'. Если хотите продолжить нажмите Enter. " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
        delete[] list1; // Очистка памяти
        delete[] list2;
        delete[] list3;
    }
    return 0;
}

