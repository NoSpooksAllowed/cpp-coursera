#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>

using TBusStop = std::map<std::string, std::vector<std::string>>;

struct BusesForStopResponse {
    const std::vector<std::string> busesForStop;
    const std::string stopInfo;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
    const std::vector<std::string> stopsForBus;
    const TBusStop busesForStop;
    const std::string bus;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
    const TBusStop& stopsForBus;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r);
