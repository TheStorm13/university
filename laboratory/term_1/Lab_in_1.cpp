#include <iostream>
#include <string>
#include <iomanip>

int get_second() {
    std::string str = "";
    bool state = true;
    std::cout << "Enter the seconds: ";
    while (state) {
        getline(std::cin, str);
        if (str.find_first_not_of("1234567890") != -1 || (str.empty()) || stoi(str) < 0) {
            std::cout << "You entered the wrong value. Enter it again: " << std::endl;
        } else
            state = false;
    }
    return stoi(str);
}

void time(unsigned int all_seconds){
    const int seconds_in_hour=3600;
    const int seconds_in_minute=60;

    unsigned int hours= all_seconds/seconds_in_hour;
    all_seconds%=seconds_in_hour;

    unsigned int minutes=all_seconds/seconds_in_minute;
    all_seconds%=seconds_in_minute;

    unsigned int seconds=all_seconds;

    std::cout.fill('0');
    std::cout<<std::setw(2)<<hours<<":"<<std::setw(2)<<minutes<<":"<<std::setw(2)<<seconds<< std::endl;
}
int main() {
    std::string ex = "";

    while (ex != "Exit") {
        unsigned int seconds= get_second();
        time(seconds);

        std::cout << "To exit, type 'Exit'. If you want to continue, type anything else. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}