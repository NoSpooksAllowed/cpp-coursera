#pragma once
#include <vector>
#include <algorithm>
#include <unordered_set>

template <typename T>
void RemoveDuplicates(std::vector<T>& elements) {
    std::unordered_set<T> s;

    auto end = std::copy_if(elements.begin(), elements.end(), elements.begin(),
        [&s](const T& i) {
            return s.insert(i).second;
    });

    elements.erase(end, elements.end());
}
