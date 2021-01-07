#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

using TBusStop = map<string, vector<string>>;

enum class QueryType {
    NewBus,
    BusesForStop,
    StopsForBus,
    AllBuses
};

struct Query {
    QueryType type;
    string bus;
    string stop;
    vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string command;

    is >> command;

    if (command == "ALL_BUSES") {
        q.type = QueryType::AllBuses;
    } else if (command == "BUSES_FOR_STOP") {
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } else if (command == "STOPS_FOR_BUS") {
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } else if (command == "NEW_BUS") {
        q.type = QueryType::NewBus;
        q.stops.clear();
        is >> q.bus;
        int stopCount;
        is >> stopCount;

        for (int i = 0; i < stopCount; i++) {
            string stop;
            is >> stop;

            q.stops.push_back(stop);
        }
    }

    return is;
}

struct BusesForStopResponse {
    const vector<string> busesForStop;
    const string stopInfo;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
    if (r.busesForStop.size() == 0) {
        os << r.stopInfo;

        return os;
    }

    for (const auto& bus : r.busesForStop) {
        os << bus << " "; 
    }

    return os;
}

struct StopsForBusResponse {
    const vector<string> stopsForBus;
    const TBusStop busesForStop;
    const string bus;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stopsForBus.size() == 0) {
        os << r.bus;

        return os;
    }
    size_t i = 0;
    for (const auto& stop : r.stopsForBus) {
        os << "Stop " << stop << ": ";

        for (const auto& busElem : r.busesForStop.at(stop)) {
            if (r.bus != busElem) {
                os << busElem << " ";
            }

            if (r.busesForStop.at(stop).size() == 1 && r.bus == busElem) {
                os << "no interchange";
            }
        }

        if (r.stopsForBus.size() - i > 1) {
            os << endl;
        }
        i++;
    }
    return os;
}

struct AllBusesResponse {
    const TBusStop& stopsForBus;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.stopsForBus.size() == 0) {
        os << "No buses";

        return os;
    }
    size_t i = 0;
    for (const auto&[key, value] : r.stopsForBus) {
        os << "Bus " << key << ": ";

        for (const auto& stop : value) {
            os << stop << " ";
        }

        if (r.stopsForBus.size() - i > 1) {
            os << endl;
        }

        i++; 
    }
    return os;
}

class BusManager {
public:
    void AddBus(const string& bus, const vector<string>& stops) {
        for (const auto& stop : stops) {
            stopsForBus[bus].push_back(stop);
            busesForStop[stop].push_back(bus);
        }
    }

    BusesForStopResponse GetBusesForStop(const string& stop) const {
        if (busesForStop.count(stop) == 0) {
            return BusesForStopResponse{vector<string>(), "No stop"};
        }

        return BusesForStopResponse{busesForStop.at(stop), ""};
    }

    StopsForBusResponse GetStopsForBus(const string& bus) const {
        if (stopsForBus.count(bus) == 0) {
            return StopsForBusResponse{vector<string>(), TBusStop(), "No bus"};
        }

        return StopsForBusResponse{stopsForBus.at(bus), busesForStop, bus};
    }

    AllBusesResponse GetAllBuses() const {
        return AllBusesResponse{stopsForBus};
    }
private:
    TBusStop busesForStop;
    TBusStop stopsForBus;
};


int main() {
    int query_count;
    Query q;

    cin >> query_count;

    BusManager bm;
    for (int i = 0; i < query_count; ++i) {
        cin >> q;
        switch (q.type) {
            case QueryType::NewBus:
                bm.AddBus(q.bus, q.stops);
            break;
            case QueryType::BusesForStop:
                cout << bm.GetBusesForStop(q.stop) << endl;
            break;
            case QueryType::StopsForBus:
                cout << bm.GetStopsForBus(q.bus) << endl;
            break;
            case QueryType::AllBuses:
                cout << bm.GetAllBuses() << endl;
            break;
        }
    }

    return 0;
}
