#include <iostream>
#include <map>
#include <string>
#include <exception>

using namespace std;

template<typename K, typename V> V& GetRefStrict(map<K,V>& m, K key);


int main() {
    map<int, string> m = {{0, "value"}};
    string& item = GetRefStrict(m, 1);

    item = "newvalue";

    cout << m[0] << endl;

    return 0;
}

template<typename K, typename V> 
V& GetRefStrict(map<K,V>& m, K key) {
    if (m.count(key) == 0) {
        throw runtime_error("runtime error"); 
    }

    V& res = m.at(key);

    return res;
}
