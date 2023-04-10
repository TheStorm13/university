#include <iostream>
#include <fstream>
#include <vector>

char *input(int &size_text) {// читаем из файла
    char *text;
    size_text = 0;

    std::ifstream infile;
    infile.open("input.txt", infile.binary);

    if (infile.is_open()) {
        infile.seekg(0, infile.end);
        size_text = infile.tellg();// считаем размер

        infile.clear();
        infile.seekg(0, infile.beg);

        text = new char[size_text + 1];


        infile.getline(text, size_text + 1, '\0');
    }
    infile.close();
    return text;
}

bool isAlpha(char symbol) {// проверка на руские буквы
    return (('А' <= symbol && symbol <= 'я') || symbol == 'ё' || symbol == 'Ё');
}

bool isSeparator(char symbol) {// проверка на разделитель
    return symbol == ' ' || symbol == '\0' || symbol == '\n' || symbol == '\r' || symbol == '\t' || symbol == '\\' ||
           symbol == 't';
}

struct machine {// автомат
    char symbol;
    int len = 0;
};
enum signals {
    a, b, c
};
enum states {
    first, second, third, error
};

std::vector<char *> isPalindrom(const char *text, const int size_text) {
    states automat[3][6];
    automat[a][first] = first;
    automat[a][second] = first;
    automat[a][third] = error;
    automat[a][error] = error;


    automat[b][first] = second;
    automat[b][second] = second;
    automat[b][third] = second;
    automat[b][error] = error;

    automat[c][first] = error;
    automat[c][second] = third;
    automat[c][third] = third;
    automat[c][error] = error;


    int len = 0;
    int start_symbol = 0;

    char *word;
    std::vector<char *> dictionary;

    char currect_symbol;
    machine automat_first, automat_second, automat_third;


    states currect_state = error;

    automat_first.symbol = text[start_symbol];

    for (int i = 0; i < size_text + 1; ++i) {
        if (isSeparator(text[i])) {// если встретился сепаратор
            if (currect_state == first || (currect_state == third && automat_first.symbol == automat_third.symbol)) {
                word = new char[len + 1];
                for (int j = start_symbol; j < i; ++j) {
                    word[j - start_symbol] = text[j];
                }
                word[i - start_symbol] = '\0';
                dictionary.push_back(word);
                currect_state = error;
            }
        } else if (isAlpha(text[i])) {// если встретилась буква
            if ((i - 1 != 0 && isSeparator(text[i - 1])) || i == 0) {
                currect_state = first;
                start_symbol = i;
                automat_second.symbol = automat_third.symbol = 0;
                automat_first.symbol = text[start_symbol];
                len = 0;
            }
            ++len;
            currect_symbol = text[i];

            if (len > 6)
                currect_state = error;

            /*           if (automat_first.symbol == currect_symbol) {
                           currect_state = automat[a][currect_state];
                       } else {
                           if (automat_second.symbol) {
                               if (automat_second.symbol == currect_symbol) {
                                   currect_state = automat[b][currect_state];
                               } else {
                                   if (automat_third.symbol) {
                                       if (automat_third.symbol == currect_symbol)
                                           currect_state = automat[c][currect_state];
                                       else {
                                           currect_state = error;
                                       }
                                   } else {
                                       automat_third.symbol = currect_symbol;
                                       currect_state = automat[c][currect_state];
                                   }
                               }
                           } else {
                               automat_second.symbol = currect_symbol;
                               currect_state = automat[b][currect_state];
                           }
                       }
           */
// проверка нынешнего символа с уже имеющимися в автомате и при необходимости его добавления
            if (automat_second.symbol) {
                if (automat_second.symbol == currect_symbol)
                    currect_state = automat[b][currect_state];
                else {
                    if (automat_third.symbol) {
                        if (automat_third.symbol == currect_symbol)
                            currect_state = automat[c][currect_state];
                        else if (automat_first.symbol == currect_symbol) {
                            currect_state = automat[a][currect_state];
                        } else {
                            currect_state = error;
                        }
                    } else {
                        automat_third.symbol = currect_symbol;
                        currect_state = automat[c][currect_state];
                    }
                }
            } else if (automat_first.symbol == currect_symbol) {
                currect_state = automat[a][currect_state];
            } else {
                automat_second.symbol = currect_symbol;
                currect_state = automat[b][currect_state];
            }
        } else
            currect_state = error;

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

    char *text;
    int size_text;
    std::vector<char *> dictionary;

    text = input(size_text);
    dictionary = isPalindrom(text, size_text);
    print(dictionary);
    for (unsigned int i = 0; i < dictionary.size(); ++i) {
        delete[] dictionary[i];
    }

    delete[] text;

    return 0;
}