#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayInt.h"

void task1() {
    ArrayInt arrayInt;
    std::cout << arrayInt.getLength() << std::endl;
    for (int i = 0; i < 10; i++) {
        arrayInt.push_back(1 + rand() % 10);
    }
    std::cout << arrayInt.getLength() << std::endl;
    arrayInt.print();
    arrayInt.sort();
    arrayInt.print();

    for (int i = 0; i < 2; ++i) {
        std::cout << "First item = " << arrayInt.pop_front() << std::endl;
        arrayInt.print();
    }

    for (int i = 0; i < 2; ++i) {
        std::cout << "Last item = " << arrayInt.pop_back() << std::endl;
        arrayInt.print();
    }
}

void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void sort(std::vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {
        int k = i;
        while (k > 0 && array.at(k - 1) < array.at(k)) {
            swap(array.at(k), array.at(k - 1));
            k -= 1;
        }
    }
}

void task2() {
    std::vector<int> array;
    for (int i = 0; i < 10; i++) {
        array.push_back(1 + rand() % 10);
    }
    for (std::vector<int>::const_iterator i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    //std::sort(array.begin(), array.end());
    sort(array);
    for (std::vector<int>::const_iterator i = array.begin(); i != array.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    int result = std::unique(array.begin(), array.end()) - array.begin();
    std::cout << result << std::endl;

}

int main() {

    //task1();
    task2();


    return 0;
}
