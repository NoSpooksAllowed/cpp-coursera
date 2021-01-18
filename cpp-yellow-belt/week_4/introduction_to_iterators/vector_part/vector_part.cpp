#include <algorithm>
#include <iostream>
#include "vector_part.h"

void PrintVectorPart(const std::vector<int>& numbers) {
    auto it = std::find_if(numbers.begin(), numbers.end(), [](int i) {
        return i < 0;
    });    

    while (it != numbers.begin()) {
        --it;
        std::cout << *it << " ";
    }
}
