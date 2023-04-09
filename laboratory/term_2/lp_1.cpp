#include <iostream>
#include <fstream>
#include <iomanip>

double *input(double &option, int &sizeArray) {
    double num;
    double *array;
    sizeArray = -1;

    std::ifstream infile;
    infile.open("input.txt");

    if (infile.is_open()) {
        while (infile >> num)//считаем количество элементов
            ++sizeArray;

        infile.clear();//сбросить все внутренние флаги ошибок
        infile.seekg(0, infile.beg);//переместить положение курсора на начало

        array = new double[sizeArray];

        infile >> option;//счситываем параметр
        for (int i = 0; i < sizeArray; ++i)
            infile >> array[i];
    }
    infile.close();
    return array;
}

double productMore(const double *array, const double &option, const int sizeArray) {
    double product = 0;
    double element;

    for (int i = 0; i < sizeArray; ++i) {
        element = array[i];
        if (option <= element && element > 0) {
            if (product == 0)
                product = 1;
            product *= element;
        }
    }
    return product;
}

void print(const double product) {
    std::ofstream outfile;
    outfile.open("output.txt");

    outfile << std::setprecision(16) << product;//выводим число целиком
    outfile.close();
}

int main() {
    double *array;
    double option;
    int sizeArray;

    array = input(option, sizeArray);//считываем строку
    print(productMore(array, option, sizeArray));//выводим произведение

    delete[] array;
    return 0;
}