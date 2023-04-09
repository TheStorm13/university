#include <iostream>
#include <fstream>
#include <vector>
//#include <Windows.h>

char *input(int &sizeArray) {
    char *array;
    sizeArray = 0;

    std::ifstream infile;
    infile.open("input.txt");

    if (infile.is_open()) {
        while (!infile.eof()) {
            infile.get();
            ++sizeArray;
        }

        infile.clear();//�������� ��� ���������� ����� ������
        infile.seekg(0, infile.beg);//����������� ��������� ������� �� ������

        array = new char[sizeArray];


        infile.getline(array, sizeArray, '\0');
    }
    --sizeArray;
    infile.close();
    return array;
}

bool checkAlpha(char symbol) {
    return (('�' <= symbol && symbol <= '�') || symbol == '�' || symbol == '�');
}

std::vector<char *> checkPalindrome(const char *array, const int sizeArray) {
    int startSymbol = 0;
    int endSymbol;
    char *word;
    int sizeWord;
    bool palindrome = true;
    std::vector<char *> dictionary;


    for (int i = 0; i < sizeArray; ++i) {
        palindrome = true;
        if (array[i] == '\n' or array[i] == '\t' or array[i] == ' ' or array[i] == '\0') {
            endSymbol = i - 1;
            sizeWord = endSymbol - startSymbol + 1;

            word = new char[sizeWord + 1];

            if (0 < sizeWord and sizeWord > 6)
                palindrome = false;

            if (array[startSymbol] == '\n' or array[startSymbol] == '\t' or array[startSymbol] == ' ' or
                array[startSymbol] == '\0')
                palindrome = false;

            for (int j = 0; endSymbol - startSymbol >= 0 and palindrome == true; ++startSymbol, --endSymbol, ++j) {
                if (tolower(array[startSymbol]) != tolower(array[endSymbol]) or
                    isalpha(array[startSymbol]) or !checkAlpha(array[startSymbol]))
                    palindrome = false;
                else {
                    *(word + j) = array[startSymbol];
                    *(word + sizeWord - j - 1) = array[endSymbol];
                }
            }
            word[sizeWord] = '\0';
            startSymbol = i + 1;
            if (palindrome == true) {
                dictionary.push_back(word);
            } else
                delete[] word;
        }

    }
    return dictionary;
}

void print(std::vector<char *> dictionary) {
    std::ofstream outfile;
    outfile.open("output.txt");
    for (char *word: dictionary) {
        outfile << word << " ";
    }
    outfile.close();
}

int main() {
    /*setlocale(LC_ALL,"Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);*/

    char *text;
    int sizeText;
    std::vector<char *> dictionary;

    text = input(sizeText);
    dictionary = checkPalindrome(text, sizeText);
    print(dictionary);
    for (unsigned int i = 0; i < dictionary.size(); ++i) {
        delete[] dictionary[i];
    }

    delete[] text;

    return 0;
}