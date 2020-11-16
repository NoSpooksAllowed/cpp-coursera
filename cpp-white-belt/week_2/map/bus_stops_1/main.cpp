#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void addNewBus(map<string, vector<string>>& busesForStop,
               map<string, vector<string>>& stopsForBus);
void printBusesForStop(const map<string, vector<string>>& busesForStop);
void printStopsForBus(const map<string, vector<string>>& busesForStop,
                      const map<string, vector<string>>& stopsForBus);
void printAllBuses(const map<string, vector<string>>& stopsForBus);

int main() {
    map<string, vector<string>> busesForStop;
    map<string, vector<string>> stopsForBus;
    int queries;
    string command;

    cin >> queries;

    for (int i = 0; i < queries; i++) {
        cin >> command;

        if (command == "NEW_BUS") {
            addNewBus(busesForStop, stopsForBus);
        } else if (command == "BUSES_FOR_STOP") {
            printBusesForStop(busesForStop);
        } else if (command == "STOPS_FOR_BUS") {
            printStopsForBus(busesForStop, stopsForBus);
        } else if (command == "ALL_BUSES") {
            printAllBuses(stopsForBus);
        }
    }

    return 0;
}

void addNewBus(map<string, vector<string>>& busesForStop,
               map<string, vector<string>>& stopsForBus) {
    string newBus;
    string newStop;
    int stopCount;

    cin >> newBus;
    cin >> stopCount;

    for (int i = 0; i < stopCount; i++) {
        cin >> newStop; 
        stopsForBus[newBus].push_back(newStop);
        busesForStop[newStop].push_back(newBus);
    }
}

void printBusesForStop(const map<string, vector<string>>& busesForStop) {
    string stop;

    cin >> stop;

    if (busesForStop.count(stop) == 0) {
        cout << "No stop" << endl;

        return;
    }
    
    for (const auto& bus : busesForStop.at(stop)) {
        cout << bus << " ";
    }

    cout << endl;
}

void printStopsForBus(const map<string, vector<string>>& busesForStop,
                      const map<string, vector<string>>& stopsForBus) {
    string bus;

    cin >> bus;
    
    if (stopsForBus.count(bus) == 0) {
        cout << "No bus" << endl;

        return;
    }
    const vector<string>& stops = stopsForBus.at(bus);

    for (const auto& stop : stops) {
        cout << "Stop " << stop << ": ";
        
        for (const auto& busElem : busesForStop.at(stop)) {
            if (bus != busElem) {
                cout << busElem << " ";
            }

            if (busesForStop.at(stop).size() == 1 && bus == busElem) {
                cout << "no interchange";
            }
        }

        cout << endl;
    }
}

void printAllBuses(const map<string, vector<string>>& stopsForBus) {
    if (stopsForBus.size() == 0) {
        cout << "No buses" << endl;;

        return;
    }

    for (const auto&[key, value] : stopsForBus) {
        cout << "Bus " << key << ": ";

        for (const auto& stop : value) {
            cout << stop << " ";
        }

        cout << endl;
    }
}
