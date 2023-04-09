#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> inputF(std::vector<std::string> arr) {
    size_t pos=0;
    std::string str;//подстрока
    std::ifstream infile;

    infile.open("input.txt");
    if (infile.is_open()) //считывание строки в файле
        getline(infile, str);
    infile.close();

    while (pos != std::string::npos) {
        pos = str.find(' '); //находим позицию пробела
        arr.push_back(str.substr(0, pos)); //берем подстроку до пробела
        str.erase(0, pos + 1); //подстроку из изначальной строки
    }

    return arr;
}

double sumOfNum(std::vector<std::string> arr) {
    double sumNum = 0;
    size_t pos = 0;

    if (arr.size() != 2) //ошибка, если аргументов больше 2
        throw std::invalid_argument("Wrong number of arguments");

    for (std::string str: arr) {
        sumNum += stod(str, &pos); //пытаемся привести подстроку к double

        if (pos != str.size()) //ошибка при некорректном значении
            throw std::invalid_argument("Argument is invalid");
    }

    return sumNum;
}

void outputF(double msg) {
    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << msg;
    outfile.close();
}
void outputF(std::string msg) {
    std::ofstream outfile;
    outfile.open("output.txt");
    outfile << msg;
    outfile.close();
}

int main() {
    std::vector<std::string> arr;
    arr = inputF(arr);

    try {
        double sumNum = sumOfNum(arr);
        outputF(sumNum);
    } catch (...) {
        outputF("Argument is invalid");
    }

    return 0;
}