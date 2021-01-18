#pragma once
#include <vector>
#include <set>

template <typename T>
std::vector<T> FindGreaterElements(const std::set<T>& elements, const T& border) {
    std::vector<T> res;

    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it > border) {
            res.push_back(*it);        
        }
    }

    return res;    
}
