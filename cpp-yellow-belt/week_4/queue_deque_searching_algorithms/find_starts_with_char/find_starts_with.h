#pragma once
#include <utility>
#include <algorithm>
#include <string>

template <typename RandomIt>
std::pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, 
    RandomIt range_end,
    char prefix
) {

    std::string lower_prefix = {prefix};
    auto lower_it = std::lower_bound(
        range_begin, 
        range_end, 
        lower_prefix
    ); 

    auto next = static_cast<char>(prefix + 1);
    std::string next_prefix = {next};
    auto upper_it = std::upper_bound(
        range_begin, 
        range_end, 
        next_prefix
    );

    return std::make_pair(lower_it, upper_it);
}
