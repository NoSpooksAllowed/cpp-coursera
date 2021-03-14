#include "test_runner.h"
#include <vector>
#include <utility>

template <typename T>
class Table {
public:
    Table(size_t rows, size_t cols) {
        Resize(rows, cols);
    } 

    std::vector<T>& operator[] (size_t idx) {
        return data[idx];
    }  

    const std::vector<T>& operator[] (size_t idx) const {
        return data[idx];
    }  

    void Resize(size_t rows, size_t cols) {
        data.resize(rows);

        for (auto& item : data) {
            item.resize(cols);
        }
        
    }

    std::pair<size_t, size_t> Size() const {
        if (data.empty() || data[0].empty()) {
            return std::make_pair(0u, 0u);
        }

        return std::make_pair(data.size(), data[0].size());
    }

private:
    std::vector<std::vector<T>> data;
};

void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}
