#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<vector<string>, int> stops;
    int queries;
    int stopNumber = 1;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        int stopLength;

        cin >> stopLength;

        vector<string> key;
        
        for (int i = 0; i < stopLength; i++) {
            string stop;

            cin >> stop;

            key.push_back(stop);
        }
        
        if (stops.count(key) == 1) {
            cout << "Already exists for " << stops[key] << endl;
        } else {
            stops[key] = stopNumber;

            stopNumber++;
            
            cout << "New bus " << stops.at(key) << endl;
        }
    }

    return 0;
}
