#include <iostream>
#include <iomanip>

using namespace std;

// Проверка на целое число
double check_double() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of(".1234567890") != -1) {
        cout << "Вы ввели неправильное значение. Введите его еще раз:" << endl;
        return check_double();
    } else {
        double integer = stod(str1);
        if (integer > 0) {
            return integer;
        } else {
            cout << "Вы ввели неправильное значение. Введите его еще раз:";
            return check_double();
        }
    }
}

double check_double_x() {
    string str1 = "";
    getline(cin, str1);// Ввод строки
    // Проверка. Если строка содержит не только цифры, то ошибка
    if (str1.find_first_not_of("-.1234567890") != -1) {
        cout << "Вы ввели неправильное значение. Введите его еще раз:" << endl;
        return check_double();
    } else {
        double x = stod(str1);
        if (x > -1 && x < 1) {
            return x;
        } else {
            cout << "Вы ввели неправильное значение. Введите его еще раз:";
            return check_double_x();
        }
    }
}

double element_row(double x, int n) {
    double member1 = 1;
    for (int i = 0; i < n; ++i) {
        member1 = member1 * x;
    }
    double member2 = 0;
    for (int i = 1; i <= n; ++i) {
        member2 += (1.0 / i);
    }
    if (n % 2 == 0) {
        return (-1) * member1 * member2;
    } else {
        return member1 * member2;
    }
}

double error(double an, double s, int n) {
    if (n % 2 == 0) {
        return (an / s);
    } else {
        return (-1) * (an / s);
    }

}

int main() {
    setlocale(LC_ALL, "Russian");
    string ex = "";
    while (ex != "Exit") {
        cout << "Введите значение погрешности или количества итераций: ";
        double a = check_double();
        cout << "Введите значение х: ";
        double x = check_double_x();
        cout << "Iteration|  " << "Member iteration|  " << "Current amount|      " << "Accuracy|  " << endl;
        if (a == int(a)) {
            double s = 0;
            double an1 = element_row(x, 1);
            s = s + an1;
            for (int i = 2; i <= a + 1; ++i) {
                double an = element_row(x, i);
                double error1 = error(an, s, i - 1);
                cout << setw(9) << i - 1 << "|" << setw(18) << an1 << "|" << setw(16) << s << "|" << setw(14) << error1
                     << "|" << endl;
                an1 = an;
                s += an;
            }
        } else {
            double error1 = 100000000000000000;
            double s = 0;
            double an1 = element_row(x, 1);
            s = s + an1;
            for (int i = 2; error1 > a; ++i) {
                double an = element_row(x, i);
                error1 = error(an, s, i - 1);
                cout << setw(9) << i - 1 << "|" << setw(18) << an1 << "|" << setw(16) << s << "|" << setw(14) << error1
                     << "|" << endl;
                an1 = an;
                s += an;
            }
        }
        cout << "Для выхода введите 'Exit'. Если хотите продолжить нажмите Enter. " << endl;
        getline(cin, ex);// Ввод слова при необходимости выхода
    }
    return 0;
}

