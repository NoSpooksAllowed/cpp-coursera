#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map<Lang, string> names;
    int64_t population;
};

int FindMaxRepetitionCount(const vector<Region>& regions);

bool operator<(const Region& lhs, const Region& rhs) {
    return tie(lhs.names, lhs.parent_std_name, lhs.population, lhs.std_name) < 
        tie(rhs.names, rhs.parent_std_name, rhs.population, rhs.std_name);
}

int main() {
    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        },
    }) << endl;

    cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
    }) << endl;

    return 0;
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
    map<Region, int> counter;
    if (regions.size() == 0) {
        return 0;
    }

    for (const auto& region : regions) {
        counter[region]++;
    }

    auto res = max_element(counter.begin(), counter.end(), 
            [](const auto& p1, const auto& p2) {
                return p1.second < p2.second;
    });

    return res->second; 
}
