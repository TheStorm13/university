#include <iostream>

/*
 * k=3;->; n=7;
 * 1234 567
 * 4321 765 (swap)
 * 567 1234 (reverse)
 * 567 1234
 */
void swap(int *array, int i, int j) {
    int buf = array[i];
    array[i] = array[j];
    array[j] = buf;
}

void reverse(int *array, int begin, int end) {
    int mid = end - begin;
    for (int i = 0; i < (mid + 1) / 2; ++i) {
        swap(array, begin + i, end - i);
    }
}

void cyclicalShift(int *array, int size, int k) {
    int mid = size - k;

    reverse(array, 0, mid - 1);
    reverse(array, mid, size - 1);
    reverse(array, 0, size - 1);
}

int main() {
    int n, k;
    std::cin >> n >> k;
    int *array = new int[n];

    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    cyclicalShift(array, n, k);

    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }

    return 0;
}