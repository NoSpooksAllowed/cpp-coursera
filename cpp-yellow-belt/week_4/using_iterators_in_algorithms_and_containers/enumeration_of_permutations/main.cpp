#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> nums(n);
    std::iota(nums.rbegin(), nums.rend(), 1);

    do {
        for (const auto& num : nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    } while (std::prev_permutation(nums.begin(), nums.end()));

    return 0;
}
