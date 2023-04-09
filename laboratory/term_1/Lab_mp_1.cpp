#include <iostream>
using namespace std;

//Ввод и проверка формата скорости
bool format_speed(){
    cout << "Please enter the initial unit of measure (m/s or km/h): " << endl;
    string format;
    getline(cin,format);//Ввод значения
    //Проверка
    if (format=="m/s"){
        return 0;
    }else if (format=="km/h"){
        return 1;
    }else{
        cout << "You entered the wrong units of measurement." << endl;
        return format_speed();
    }
}
//Ввод и проверка значения скорости
double unit_speed(){
    cout << "Please enter the speed: " << endl;
    string unit;
    getline(cin,unit);//Ввод значения
    //Проверка. Если строка содержит не только цифры и точку, то ошибка
    if (unit.find_first_not_of(".1234567890")!=-1){
        cout << "You entered the wrong speed." << endl;
        return unit_speed();
    }else{
        long double unit_d = stod(unit);//преобразование строки в double
        //Проверка на положительное число
        if (unit_d<0){
            cout << "You entered the wrong speed." << endl;
            return unit_speed();
        }else{
            return unit_d;
        }
    }
}
//Конвертация скорости из одной системы в другую
void convert_speed(double unit,bool format){
    if (format==0){
        cout<< unit*3.6 << " km/h" << endl;
    }else{
        cout<< unit/3.6 << " m/s" << endl;
    }
}

int main() {
    string exit="";
    //Цикл с условием выхода
    while (exit!="Exit"){
        bool format=format_speed();//Ввод формата
        double unit=unit_speed();//Ввод скорости
        convert_speed(unit,format);//Конвертация скорости и ее вывод
        cout << "To exit, type 'Exit'. If you want to continue, press Enter. " << endl;
        getline(cin,exit);//Ввод слова при необходимости выхода
    }
    return 0;
}
