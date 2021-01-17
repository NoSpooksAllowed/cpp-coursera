#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    for (const auto& stop : stops) {
        stopsForBus[bus].push_back(stop);
        busesForStop[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    if (busesForStop.count(stop) == 0) {
        return BusesForStopResponse{vector<string>(), "No stop"};
    }

    return BusesForStopResponse{busesForStop.at(stop), ""};
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    if (stopsForBus.count(bus) == 0) {
        return StopsForBusResponse{vector<string>(), TBusStop(), "No bus"};
    }

    return StopsForBusResponse{stopsForBus.at(bus), busesForStop, bus};
}

AllBusesResponse BusManager::GetAllBuses() const {
    return AllBusesResponse{stopsForBus};
}
