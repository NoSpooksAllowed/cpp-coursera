#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

template<typename T> T Sqr(T x);
template<typename T> vector<T> Sqr(vector<T> v);
template<typename K, typename V> map<K, V> Sqr(map<K, V> m);
template<typename First, typename Second> pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2);

int main() {

    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    vector<map<int, pair<int, int>>> vmp = { {{4, {3, 3}}} };

    for (const auto& x : Sqr(vmp)) {
        for (const auto& y : x) {
            cout << y.first << y.second.first << y.second.first <<  endl;
        }
    }
    
    return 0;
}

template<typename T>
T Sqr(T x) {
    return x * x;
}

template<typename T>
vector<T> Sqr(vector<T> v) {
    vector<T> res;
    for (const auto& elem : v) {
        res.push_back(Sqr(elem));
    }

    return res;
}

template<typename K, typename V> map<K, V> Sqr(map<K, V> m) {
    map<K, V> res;
    for (const auto&[key, value] : m) {
        res[key] = Sqr(value);
    }

    return res;
}

template<typename First, typename Second> 
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2) {
    First f = p1.first * p2.first;
    Second s = p1.second * p2.second;

    return make_pair(f, s);
}
