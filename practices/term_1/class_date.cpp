#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

class simple_date {
public:
    enum Month {
        jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };

    simple_date(int year, Month month, int day) : y(year), m(month), d(day) { check(); }

    int year() const { return y; }

    Month month() const { return m; }

    int day() const { return d; }

    void year(int year) {
        y = year;
        check();
    }

    void day(int day) {
        d = day;
        check();
    }

    void month(Month month) {
        m = month;
        check();
    }

    bool is_leap() const {
        return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
    }

    int days_in_month() const {
        int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (is_leap() && (m == feb)) ? 29 : days[m - 1];
    }

    simple_date &operator++() {
        if (d < days_in_month())
            ++d;
        else {
            d = 1;
            m = (m == dec) ? jan : Month(m + 1);
            if (m == jan) {
                ++y;
                check_year();
            }
        }
        return *this;
    }

    simple_date operator++(int) {
        simple_date old(*this);
        operator++();
        return old;
    }

    simple_date &operator--() {
        if (d > 1)
            --d;
        else {
            m = (m == jan) ? dec : Month(m - 1);
            if (m == dec) {
                --y;
                check_year();
            }
            d = days_in_month();
        }
        return *this;
    }

    simple_date operator--(int) {
        simple_date old(*this);
        operator--();
        return old;
    }

private:
    int y;
    Month m;
    int d;

    void check_year() {
        if (y <= 0)
            throw runtime_error("Incorrect year");
    }

    void check_day() {
        if (d <= 0 || d > days_in_month())
            throw runtime_error("Incorrect day");
    }

    void check() {
        check_year();
        check_day();
    }
};


ostream &operator<<(ostream &os, const simple_date &date) {
    char old_fill = os.fill('0');
    return os << setw(2) << date.day() << '.' << setw(2) << date.month() << '.' << setw(4) << date.year()
              << setfill(old_fill);
}

istream &operator>>(istream &out){


}

int main() {
    try {
        cout << setfill('*') << setw(10) << "test" << endl;

        simple_date date(2020, simple_date::jan, 1);
        //date.y
        //cout << date.day() << '.' << date.month() << '.' << date.year() << endl;
        cout << date << endl;
        cout << date.is_leap() << endl;
        cout << date.days_in_month() << endl;

        /*cout << "Enter day" << endl;
        int a;
        cin >> a;
        date.day(a);*/
        cout << date-- << endl;
        cout << date << endl;
        cout << setw(10) << "test" << endl;
    }
    catch (runtime_error &e) {
        cout << e.what() << endl;
    }
}