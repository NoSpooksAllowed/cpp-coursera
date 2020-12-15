#include <iostream>
#include <cstdint>
#include <vector>

using namespace std;

struct BlockSize {
    uint64_t width;
    uint64_t height;
    uint64_t length;
};


int main() {
    int n;
    uint32_t density;
    uint64_t sum = 0;
    cin >> n;
    cin >> density;

    for (int i = 0; i < n; i++) {
        BlockSize block;
        cin >> block.width;
        cin >> block.height;
        cin >> block.length;

        sum += density * (block.width * block.height * block.length);
    }

    cout << sum << endl;

    return 0;
}
