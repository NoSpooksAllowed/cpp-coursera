#include <iostream>
#include "split_into_words.h"

int main() {
    std::string s = "C Cpp Java Python";

    std::vector<std::string> words = SplitIntoWords(s);
    std::cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            std::cout << "/";
        }
        std::cout << *it;
    }
    std::cout << std::endl;

    return 0;
}
