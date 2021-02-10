#include "find_nearest_element.h"

std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border) {
    const auto it = numbers.lower_bound(border);

    if (it == numbers.begin()) {
        return it;
    }

    const auto prev_it = prev(it);

    if (it == numbers.end() || border - *prev_it <= *it - border) {
        return prev_it;
    }

    return it;
}
