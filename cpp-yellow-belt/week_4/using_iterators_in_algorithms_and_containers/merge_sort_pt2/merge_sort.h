#pragma once
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

    const size_t third_size = elements.size() / 3;

    MergeSort(elements.begin(), elements.begin() + third_size);
    MergeSort(elements.begin() + third_size, elements.end() - third_size);
    MergeSort(elements.end() - third_size, elements.end());
    std::vector<typename RandomIt::value_type> res;

    std::merge(elements.begin(), elements.begin() + third_size, elements.begin() + third_size, elements.end() - third_size, std::back_inserter(res));
    std::merge(res.begin(), res.end(), elements.end() - third_size, elements.end(), range_begin);
}
