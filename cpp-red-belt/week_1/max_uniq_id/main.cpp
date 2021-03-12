#include <string>
#include <vector>

#define f(x, y) h(x, y)
#define h(x, y) x##y
#define UNIQ_ID f(id, __LINE__)

int main() {
    int UNIQ_ID = 0;
    std::string UNIQ_ID = "hello";
    std::vector<std::string> UNIQ_ID = { "hello", "world" };
    std::vector<int> UNIQ_ID = { 1, 2, 3, 4 };
}
