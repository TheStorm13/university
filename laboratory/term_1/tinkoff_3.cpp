#include <iostream>
#include <string>

std::string getN() {
    std::string str;
    getline(std::cin, str);
    return str;
}

void AI(std::string str) {
    char symbol;
    bool ch11,ch34;
    for (int i = 0; i < str.size(); ++i) {
        symbol = str[i];
        if (symbol=='0')
            if (ch11==true){
                ch11=false;
                std::cout<<"1 3"<<std::endl;
            }else{
                ch11=true;
                std::cout<<"1 1"<<std::endl;
            }
        if (symbol=='1')
            if (ch34==true){
                ch34=false;
                std::cout<<"1 4"<<std::endl;
            }else{
                ch34=true;
                std::cout<<"3 4"<<std::endl;
            }
    }
}

int main() {
    std::string str= getN();
    AI(str);
    return 0;
}