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

std::vector<int> getSpeeds() {
    std::vector<int> speeds;
    int speed;
    int quantity = getN();
    for (int i = 0; i < quantity; ++i) {
        speed = getN();
        speeds.push_back(speed);
    }
    return speeds;
}

std::vector<int> nowSpeed(std::vector<int> speeds) {
    for (int i = 1; i < speeds.size(); ++i) {
        if (speeds[i] > speeds[i - 1])
            speeds[i] = speeds[i - 1];
    }
    return speeds;
}

int main() {
    std::vector<int> speeds;
    speeds = getSpeeds();
    speeds = nowSpeed(speeds);
    for (int i = 0; i < speeds.size(); ++i) {
        std::cout << speeds[i] << " ";
    }
    return 0;
}