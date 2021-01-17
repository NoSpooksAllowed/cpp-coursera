#include "responses.h"

using namespace std;

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

