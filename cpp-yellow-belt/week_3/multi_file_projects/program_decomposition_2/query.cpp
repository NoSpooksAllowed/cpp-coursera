#include "query.h"

using namespace std;

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

