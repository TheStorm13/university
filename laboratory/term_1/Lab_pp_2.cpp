#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

double get_double() {
    std::string str = "";
    bool state = true;
    double number;
    std::size_t pos{};

    std::cout << "Enter the value of the error or the number of iterations:  ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stod(str, &pos);

            if (pos != str.size() || number <= 0) {
                throw std::invalid_argument("Argument is invalid. ");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

double get_x() {
    std::string str = "";
    bool state = true;
    double number;
    std::size_t pos{};

    std::cout << "Enter the value of x:  ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stod(str, &pos);

            if (pos != str.size() || 1 < number < -1) {
                throw std::invalid_argument("Argument is invalid. ");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

std::vector<long double>
array_add(std::vector<long double> array, long double x, int n, long double An, long double S, long double En) {
    array.push_back(x);
    array.push_back(n);
    array.push_back(An);
    array.push_back(S);
    array.push_back(En);
    return array;
}

double long calculat_An(long double x, int n) {
    long double buffer1 = 0;
    long double buffer2 = 1;
    for (int i = 1; i <= n; ++i) {
        buffer1 += (1.0 / i);
        buffer2 *= x;
    }
    return ((n - 1) % 2 == 0 ? 1 : -1) * buffer1 * buffer2;
}


double long error_An(long double Sn, int n, long double x) {
    long double An1 = calculat_An(x, n + 1);
    long double result = An1 / Sn;
    return result<0?-result:result;
}


long double Sum_n(std::vector<long double> &array, long double x, long double err) {
    int n = 1;
    long double An;
    long double S = 0;
    long double En = 10000000000000;
    if (int(err) == err) {
        while (n <= err) {
            int j = 0;
            bool arr_flag = 0;
            while (array.empty() == false && j < array.size()) {
                if (x == array[j] && n == array[j + 1]) {
                    std::cout << "Arr ";
                    std::cout << std::setw(9) << n << "|" << std::setw(18) << array[j + 2] << "|" << std::setw(16)
                              << array[j + 3]
                              << "|" << std::setw(14) << array[j + 4]
                              << "|" << std::endl;
                    An = array[j + 2];
                    S = array[j + 3];
                    arr_flag = 1;
                }
                j += 5;
            }
            if (arr_flag == 0) {
                An = calculat_An(x, n);
                S += An;
                En = error_An(S, n, x);
                array = array_add(array, x, n, An, S, En);
                std::cout << "Cul ";
                std::cout << std::setw(9) << n << "|" << std::setw(18) << An << "|" << std::setw(16)
                          << S
                          << "|" << std::setw(14) << En
                          << "|" << std::endl;
            }
            n += 1;
        }
    } else {
        while (En >= err) {
            int j = 0;
            bool arr_flag = 0;
            while (array.empty() == false && j < array.size()) {
                if (x == array[j] && n == array[j + 1]) {
                    std::cout << "Arr ";
                    std::cout << std::setw(9) << n << "|" << std::setw(18) << array[j + 2] << "|" << std::setw(16)
                              << array[j + 3]
                              << "|" << std::setw(14) << array[j + 4]
                              << "|" << std::endl;
                    An = array[j + 2];
                    S = array[j + 3];
                    En = array[j + 4];
                    arr_flag = 1;
                }
                j += 5;
            }
            if (arr_flag == 0) {
                An = calculat_An(x, n);
                S += An;
                En = error_An(S, n, x);
                array = array_add(array, x, n, An, S, En);
                std::cout << "Cul ";
                std::cout << std::setw(9) << n << "|" << std::setw(18) << An << "|" << std::setw(16)
                          << S
                          << "|" << std::setw(14) << En
                          << "|" << std::endl;
            }
            n += 1;
        }
    }
}


int main() {
    std::string ex = "";
    std::vector<long double> array;
    while (ex != "Exit") {
        long double x = get_x();
        long double err = get_double();
        Sum_n(array, x, err);
        std::cout << std::endl << "To exit, type 'Exit'. If you want to continue, type anything else. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}