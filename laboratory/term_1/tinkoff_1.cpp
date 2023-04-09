#include <iostream>
#include <string>
#include <vector>

int getN() {
    std::string str = "";
    int number;
    std::size_t pos{};
    getline(std::cin, str);
    try {
        number = stoi(str, &pos);
        if (pos != str.size() || number < 1) {
            throw std::invalid_argument("Argument is invalid\n");
        }
    }
    catch (...) {
        number = 0;
    }
    return number;
}

int countAngle(int n) {
    int angle = n % 3 == 0 ? n / 3 * 2 : 0;
    return angle;
}

int countPermutation(int angle) {
    int permutation = 1;
    for (int i = 2; i < angle; ++i) {
        permutation *= i;
    }
    permutation *= angle;
    return permutation;
}

int main() {
    int n = getN();
    int angle = countAngle(n);
    int permutation = countPermutation(angle);
    std::cout << permutation;
    return 0;
}