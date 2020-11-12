#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q;
    vector<bool> people;

    cin >> q;
    
    for (int i = 0; i < q; i++) {
        string command_name;
        cin >> command_name;

        if (command_name == "COME") {
            int n;
            cin >> n;
            
            people.resize(people.size() + n);
        } else if (command_name == "WORRY") {
            int j;
            cin >> j;
            people[j] = true;
        } else if (command_name == "QUIET") {
            int j;
            cin >> j;
            people[j] = false;
        } else if (command_name == "WORRY_COUNT") {
            int sum = 0;
            for (auto elem : people) {
                if (elem == true) {
                    sum++;
                }
            }

            cout << sum << endl;
        }
    }
    return 0;
}
