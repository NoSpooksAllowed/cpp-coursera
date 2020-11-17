#include "build_map_values_set.h"

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> res;

    for (const auto& [key, value] : m) {
        res.insert(value);
    }

    return res;
}
