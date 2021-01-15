#include <iostream>
#include "sum_reverse_sort.h"

using namespace std;

int main() {
    
    cout << Sum(5, 10) << endl;
    cout << Reverse("hello") << endl;
    
    vector<int> nums =  {10, 4, 2, 15, 1, 3};
    Sort(nums);

    for (const auto& num : nums) {
        cout << num << " ";
    }

    cout << endl;
    return 0;
}
