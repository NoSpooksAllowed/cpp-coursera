#include "database.h"

void Database::Add(const Date& date, const std::string& event) {
    if (checker[date].count(event) == 0) {
        checker[date].insert(event);
        storage[date].push_back(event);
    }
}

void Database::Print(std::ostream& output) const {
    for (const auto&[key, value] : storage) {
        for (const auto& event : value) {
            output << key << " " <<  event << std::endl;
        }
    }
}

std::pair<Date, std::string> Database::Last(const Date& date) const {
    if (storage.empty()) {
        throw std::invalid_argument("Empty storage");
    }

    auto upper = storage.upper_bound(date);

    if (upper == storage.begin()) {
        throw std::invalid_argument("Small date");
    }

    --upper;

    return std::make_pair(upper->first, upper->second.back());
}

std::ostream& operator<<(
    std::ostream& output, 
    const std::pair<Date, 
    std::vector<std::string>>& items) {
    
    for (const auto& item : items.second) {
        output << items.first << " " << item << std::endl;
    } 

    return output;
}

bool operator<(
    const std::pair<Date, std::string>& lhs, 
    const std::pair<Date, std::string>& rhs) {
    
    return lhs.first < rhs.first;
}

bool operator==(
    const std::pair<Date, std::string>& lhs, 
    const std::pair<Date, std::string>& rhs) {

    return lhs.first == rhs.first && lhs.second == rhs.second;
}

std::ostream& operator<<(
    std::ostream& output, 
    const std::pair<Date, 
    std::string>& items) {

    output << items.first << " " << items.second;

    return output;
}
