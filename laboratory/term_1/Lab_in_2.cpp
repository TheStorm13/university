#include <iostream>
#include <vector>
#include <string>

std::vector<double> calculate_a(double x1, double x2, double x3, double y1, double y2, double y3) {
    double a = (y3 - y1 - (y2 - y1) * (x3 - x1) / (x2 - x1)) / ((x3 - x1) * (x3 - x2));
    double b = (y2 - y1 - a * (x2 * x2 - x1 * x1)) / (x2 - x1);
    double c = y1 - x1 * x1 * a - x1 * b;

    /*double a = (y3 - (x3 * (y2 - y1) + x2 * y1 - x1 * y2) / (x2 - x1)) / (x3 * (x3 - x1 - x2) + x1 * x2);
    double b = (y2 - y1) / (x2 - x1) - a * (x1 + x2);
    double c = (x2 * y1 - x1 * y2) / (x2 - x1) + a * x1 * x2;*/

    std::vector<double> arr = {a, b, c};
    return arr;
}

double get_element(std::string name) {
    std::string str = "";
    bool state = true;
    double test;
    std::size_t pos{};
    std::cout << "Enter the " << name << ": ";
    while (state) {
        getline(std::cin, str);
        try{
            test=stod(str,&pos);
            if (pos!=str.size()){
                std::cerr << "Argument is invalid\n";
                throw std::invalid_argument("Argument is invalid\n") ;
            }
            state=false;
        }
        catch (const std::invalid_argument&){
            std::cout<<"Argument is invalid\n";
        }
    }
    return test;
}

int main() {
    std::string ex = "";
    while (ex != "Exit") {
        std::vector<double> arr;
        double x1 = get_element("x1");
        double y1 = get_element("y1");
        double x2 = get_element("x2");
        double y2 = get_element("y2");
        double x3 = get_element("x3");
        double y3 = get_element("y3");
        arr = calculate_a(x1, x2, x3, y1, y2, y3);
        std::cout << "y=" << std::noshowpos << arr[0] << "x^2" << std::showpos << arr[1] << "x" << std::showpos
                  << arr[2] << std::endl;
        std::cout << "To exit, type 'Exit'. If you want to continue, type anything else. type anything else. " << std::endl;
        getline(std::cin, ex);
    }
    return 0;
}
