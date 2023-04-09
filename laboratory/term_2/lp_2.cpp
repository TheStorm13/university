#include <iostream>
#include <fstream>
#include <iomanip>

double **input(int &lines, int &columns) {
    double **matrix;

    std::ifstream infile;
    infile.open("input.txt");

    if (infile.is_open()) {
        infile >> lines;
        infile >> columns;

        matrix = new double *[lines];

        for (int i = 0; i < lines; ++i) {
            matrix[i] = new double[columns];
            for (int j = 0; j < columns; ++j)
                infile >> matrix[i][j];
        }
    }
    infile.close();
    return matrix;
}

double *sumInColumns(double **matrix, const int &columns, const int &lines) {
    double *sumColumns = new double[columns];

    for (int i = 0; i < columns; ++i) {
        sumColumns[i] = 0;
    }

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            sumColumns[j] += matrix[i][j];
    }

    for (int i = 0; i < columns; ++i) {// делим сумму по стобцам на количество элементов в столбце
        sumColumns[i] /= lines;
    }

    return sumColumns;
}

void print(const double *sumColumns, const int &columns) {
    std::ofstream outfile;
    outfile.open("output.txt");

    for (int i = 0; i < columns; ++i) {
        outfile << std::fixed << std::showpoint;
        outfile << std::setprecision(8);
        outfile << sumColumns[i] << " ";
    }

    outfile.close();
}

int main() {
    double **matrix;
    double *sumColumns;
    int lines;
    int columns;

    matrix = input(lines, columns);//считываем строку
    sumColumns = sumInColumns(matrix, columns, lines);//находим среднее значение по столбцам
    print(sumColumns, columns);//выводим произведение

    for (int i = 0; i < lines; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] sumColumns;

    return 0;
}