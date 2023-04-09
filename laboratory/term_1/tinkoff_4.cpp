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
        if (pos != str.size()) {
            throw std::invalid_argument("Argument is invalid\n");
        }
    }
    catch (...) {
        number = 0;
    }
    return number;
}


int countDel(int number) {
    int sumDel = 0;
    for (int i = 1; i <= number; ++i) {
        if (number % i == 0)
            sumDel += 1;
    }
    return sumDel;
}

void findMax(int number) {
    int maxNumber;
    int maxSumDel = 0;
    int sumDel;
    for (int i = 1; i <= number; ++i) {
        sumDel = countDel(i);
        if (sumDel >= maxSumDel) {
            maxSumDel = sumDel;
            maxNumber = i;
        }
    }
    std::cout << maxNumber << std::endl << maxSumDel;
}

int main() {
    int n = getN();
    findMax(n);


    return 0;
}