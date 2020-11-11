#include <iostream>


void UpdateIfGreater(int first, int& second);

int main() {
    int a, b;

    std::cin >> a >> b;

    UpdateIfGreater(a, b);

    std::cout << "b == " << b << std::endl;

    return 0;
}

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        second = first;
    }
}
