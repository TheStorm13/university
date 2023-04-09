#include <iostream>
#include <string>
#include <vector>

int getN() {
    std::string str = "";
    int number;
    std::size_t pos{};
    getline(std::cin, str);
    try {
        number = stoi(str, &pos);
        if (pos != str.size()) {
            throw std::invalid_argument("Argument is invalid\n");
        }
    }
    catch (...) {
        number = 0;
    }
    return number;
}

int nDel(int n) {
    int del = -1;
    int sumN = 0;
    for (int i = 0; i <= n; ++i) {
        sumN += i;
    }
    if (sumN % 3 == 0)
        del = sumN / 3;
    return del;
}

void foundGroup(int n) {
    int del = nDel(n);
    std::vector<int> nums;
    int goal = 0;
    std::vector<int> group;
    if (del == -1)
        std::cout << del;
    else {
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        for (int j = 0; j < 3; ++j) {
            goal = 0;
            group = {};
            std::cout << std::endl;
            for (int i = nums.size()-1; goal != del; --i) {
                if (goal + nums[i] <= del) {
                    goal += nums[i];
                    if (nums[i] != 0)
                        group.push_back(nums[i]);
                    nums[i] = 0;
                }
            }
            std::cout << group.size() << std::endl;
            for (int j = 0; j < group.size(); ++j) {
                std::cout << group[j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    int n = getN();
    std::vector<int> group;
    foundGroup(n);
    return 0;
}