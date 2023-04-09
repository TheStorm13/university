#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

vector<int> merge_sort(vector<int> array_first, vector<int> array_second) {
    vector<int> buffer = {};
    while (array_first.empty() == false or array_second.empty() == false) {
        if (array_first.size() > 0 && array_second.empty()) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        } else if (array_second.size() > 0 && array_first.empty()) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        } else if (array_first[0] < array_second[0]) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        } else if (array_first[0] >= array_second[0]) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
    }
    return buffer;
}

vector<int> merge(vector<int> array, int begin, int end) {
    int mid = (end + begin) / 2;
    if (begin == end) return {array[begin]};
    else return merge_sort(merge(array, begin, mid), merge(array, mid + 1, end));
}

// Проверка на целое число
int get_size() {
    std::string str = "";
    bool state = true;
    int  number;
    std::size_t pos{};

    std::cout << "Enter the size of the array: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size() || number < 2) {
                //std::cerr << "1\n";
                throw std::invalid_argument("Argument is invalid\n");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}

int get_element() {
    std::string str = "";
    bool state = true;
    double number;
    std::size_t pos{};

    std::cout << "Enter the element of the array: ";

    while (state) {
        getline(std::cin, str);

        try {
            number = stoi(str, &pos);

            if (pos != str.size()) {
                throw std::invalid_argument("Argument is invalid. ");
            }
            state = false;
        }
        catch (...) {
            std::cout << "You entered the wrong value. Enter it again: ";
        }
    }
    return number;
}


char get_method() {
    string str = "";
    bool state = true;

    std::cout << "Choose the method of filling the array. Random - \"r\", nearly sorted - \"n\", manually - \"m\": ";

    while (state) {
        getline(cin, str);

        if (!(str == "r" || str == "n" || str == "m") || str.empty()) {
            cout << "You entered the wrong value. Enter it again: ";
        } else
            state = false;
    }
    return str == "r" ? 'r' : str == "n" ? 'n' : 'm';
}

vector<int> array_random(vector<int> array, int size_array) {
    srand(time(0));

    while (array.size() < size_array) {
        int random = rand() % 100;
        array.push_back(random);
    }
    return array;
}

vector<int> array_filling(vector<int> array, int size_array, char method) {
    switch (method) {
        case 'r':
            return array_random(array, size_array);
            break;
        case 'n':
            array = array_random(array, size_array);
            sort(array.begin(), array.end() - array.size() / 2);
            return array;
            break;
        case 'm':
            while (array.size() < size_array) {
                array.push_back(get_element());
            }
            return array;
            break;
    }
}

//double runtime(){}

/*
vector<int> merge(vector<int> array_first, vector<int> array_second) {
    vector<int> buffer = {};
    while (array_first.empty() == false or array_second.empty() == false) {
        if (array_first.size() > 0 && array_second.empty()) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        }
        else if (array_second.size() > 0 && array_first.empty()) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
        else if (array_first[0] < array_second[0]) {
            buffer.push_back(array_first[0]);
            array_first.erase(array_first.begin());
        }
        else if (array_first[0] >= array_second[0]) {
            buffer.push_back(array_second[0]);
            array_second.erase(array_second.begin());
        }
    }
    return buffer;
}
void merge_sorting(vector<vector<int>> array,int limit) {
    if (array.size() % 2 == 1) {
        if (array[1][0] > array[0][0]) {
            array[1] = {array[0][0],array[1][0]};
            array.erase(array.begin());
        }
        else {
            array[1] = { array[1][0],array[0][0]};
            array.erase(array.begin());
        }
    }
    int steps = 1;
    for (int i = 2; steps < array.size();i*2) {
        steps +=1;
    }
    vector<int> buffer;
    while(array.size() != 1) {
        int stop_point = array.size();
        for (int j = 1; j < stop_point; ++j){
            buffer = merge(array[0], array[1]);
            array.erase(array.begin());
            array.erase(array.begin());
            array.push_back(buffer);
            buffer = {};
        }
    }

        for (int j = 0; j < limit; ++j) {
            cout << array[0][j] << "    ";
    }
        cout << endl;
}

vector<int> merge(vector<int> array) {
    int steps = 1;
    for (int i = 2; steps < array.size(); i * 2) {
        steps += 1;
    }
    vector<int> buffer = {};
    for (int i = 1; i <= steps; ++i) {
        for (int j = 0; j < steps; ++j) {


        }

    }

    return array;
}
*/

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    string ex = "";

    while (ex != "Exit") {
        vector<int> arr = {};

        int size_array = get_size();
        char method = get_method();
        arr = array_filling(arr, size_array, method);
        int limit = 20 < arr.size() ? 20 : arr.size();

        cout << "Initial array" << endl;
        for (int i = 0; i < limit; ++i) {
            cout << arr[i] << "    ";
        }

        auto start_merge = high_resolution_clock::now();
        vector<int> arr_merge = merge(arr, 0, arr.size() - 1);
        auto this_merge = high_resolution_clock::now();
        duration<double, std::milli> time_merge = this_merge - start_merge;


        cout << endl << endl << "Sorted array by merge" << endl;
        for (int i = 0; i < limit; ++i) {
            cout << arr_merge[i] << "    ";
        }
        cout << endl << "Merge sorting time: " << time_merge.count() << endl;

        auto start_lib = high_resolution_clock::now();
        sort(arr.begin(), arr.end());
        auto this_lib = high_resolution_clock::now();
        duration<double, std::milli> time_lib = this_lib - start_lib;

        cout << endl << "Sorted array by library" << endl;

        for (int i = 0; i < limit; ++i) {
            cout << arr[i] << "    ";
        }
        cout << endl << "Library sorting time: " << time_lib.count() << endl;

        cout << endl << "Library sorting is " << time_merge.count() / time_lib.count() << "x faster." << endl;

        cout << endl << "To exit, type 'Exit'. If you want to continue, type anything else. " << endl;
        getline(cin, ex);
    }
    return 0;
}

