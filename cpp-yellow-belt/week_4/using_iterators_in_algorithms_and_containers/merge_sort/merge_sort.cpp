#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 2) {
        return;
    }

    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);

    const size_t half_size = elements.size() / 2;

    MergeSort(elements.begin(), elements.begin() + half_size);
    MergeSort(elements.begin() + half_size, elements.end());
    
    std::merge(elements.begin(), elements.begin() + half_size, elements.begin() + half_size, elements.end(), range_begin);
}
