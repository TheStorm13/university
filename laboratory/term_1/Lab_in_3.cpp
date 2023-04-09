#include <iostream>
#include <string>
#include <vector>

int get_size() {
    std::string str = "";
    bool state = true;
    int  number;
    std::size_t pos{};

    std::cout << "Enter the size matrix: ";
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

int get_element(int size, int i, int j) {
    std::string str = "";
    bool state = true;
    int  number;
    std::size_t pos{};

    std::cout << "Enter the element " << i << "," << j << ": ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size() || number > size * size) {
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

std::vector<std::vector<int>> fill_matrix(int size, std::vector<std::vector<int>> matrix) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = get_element(size, i, j);
        }
    }
    return matrix;
}

bool is_magic_matrix(std::vector<std::vector<int>> matrix) {
    bool flag = 1;
    std::vector<int> sum_matrix(2 * matrix.size() + 2);

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix.size(); ++j) {

            sum_matrix[i] += matrix[i][j];
            sum_matrix[matrix.size() + j] += matrix[i][j];
            if (i == j)
                sum_matrix[2 * matrix.size()] += matrix[i][j];
            if (i + j == matrix.size() - 1)
                sum_matrix[2 * matrix.size() + 1] += matrix[i][j];
        }
    }

    for (int k = 0; k < sum_matrix.size() - 1; ++k)
        flag *= (sum_matrix[k] == sum_matrix[k + 1]);

    return flag;
}

void print(std::vector<std::vector<int>> matrix, bool flag) {
    for (int i = 0; i < matrix.size(); ++i) {
        std::cout << std::endl;

        for (int j = 0; j < matrix.size(); ++j) {
            std::cout << matrix[i][j] << " ";
        }
    }
    if (flag == 1)
        std::cout << std::endl << "This is a magic matrix" << std::endl;
    else
        std::cout << std::endl << "This is not a magic matrix" << std::endl;

}

int main() {
    std::string ex = "";

    while (ex != "Exit") {
        int size_matrix = get_size();
        std::vector<std::vector<int>> matrix(size_matrix, std::vector<int>(size_matrix));
        matrix = fill_matrix(size_matrix, matrix);
        bool magic_matrix = is_magic_matrix(matrix);
        print(matrix, magic_matrix);

        std::cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}