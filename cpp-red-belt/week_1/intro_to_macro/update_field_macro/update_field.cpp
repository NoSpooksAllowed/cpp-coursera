#include "airline_ticket.h"
#include "test_runner.h"

#include <iomanip>

bool operator<(const Time& lhs, const Time& rhs) {
    return std::make_tuple(lhs.hours, lhs.minutes) < std::make_tuple(rhs.hours, rhs.minutes);
}

bool operator==(const Time& lhs, const Time& rhs) {
    return std::make_tuple(lhs.hours, lhs.minutes) == std::make_tuple(rhs.hours, rhs.minutes);
}

std::ostream& operator<<(std::ostream& output, const Time& time) {
    output << std::setfill('0') << std::setw(2) << time.hours
            << ':' << std::setw(2) << time.minutes;

    return output;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) < std::make_tuple(rhs.year, rhs.month, rhs.day);
}

bool operator==(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.year, lhs.month, lhs.day) == std::make_tuple(rhs.year, rhs.month, rhs.day);
}

std::ostream& operator<<(std::ostream& output, const Date& date) {
    output << std::setfill('0') << std::setw(4) << date.year
            << '-' << std::setw(2) << date.month
            << '-' << std::setw(2) << date.day;

    return output;
}

std::istream& operator>>(std::istream& input, Date& date) {
    std::string s;
    input >> s;
    std::stringstream ss(s);

    char delim;

    auto checkInputErr = [s](const std::stringstream& ss, char delim, char symbol) {
        if (ss.fail() || delim != symbol) {
            throw std::invalid_argument("Wrong date format: " + s);
        }
    };

    ss >> date.year;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> date.month;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> date.day;
    if (!ss.eof() || ss.fail()) {
        throw std::invalid_argument("Wrong date format: " + s);
    }

    return input;
}

std::istream& operator>>(std::istream& input, Time& time) {
    std::string s;
    input >> s;
    std::stringstream ss(s);

    char delim;

    auto checkInputErr = [s](const std::stringstream& ss, char delim, char symbol) {
        if (ss.fail() || delim != symbol) {
            throw std::invalid_argument("Wrong date format: " + s);
        }
    };

    ss >> time.hours;
    ss >> delim;
    checkInputErr(ss, delim, ':');
    ss >> time.minutes;
    if (!ss.eof() || ss.fail()) {
        throw std::invalid_argument("Wrong date format: " + s);
    }

    return input;
}



#define UPDATE_FIELD(ticket, field, values) {                     \
    std::map<std::string, std::string>::const_iterator it;        \
                                                                  \
    it = values.find(#field);                                     \
    if (it != values.end()) {                                     \
        std::istringstream is(it->second);                        \
        is >> ticket.field;                                       \
    }                                                             \
}    

void TestUpdate() {
    AirlineTicket t;
    t.price = 0;

    const std::map<std::string, std::string> updates1 = {
        { "departure_date", "2018-2-28" },
        { "departure_time", "17:40" },
    };
    UPDATE_FIELD(t, departure_date, updates1);
    UPDATE_FIELD(t, departure_time, updates1);
    UPDATE_FIELD(t, price, updates1);

    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 0);

    const std::map<std::string, std::string> updates2 = {
        { "price", "12550" },
        { "arrival_time", "20:33" },
    };
    UPDATE_FIELD(t, departure_date, updates2);
    UPDATE_FIELD(t, departure_time, updates2);
    UPDATE_FIELD(t, arrival_time, updates2);
    UPDATE_FIELD(t, price, updates2);

    // updates2 не содержит ключей "departure_date" и "departure_time", поэтому
    // значения этих полей не должны измениться
    ASSERT_EQUAL(t.departure_date, (Date{ 2018, 2, 28 }));
    ASSERT_EQUAL(t.departure_time, (Time{ 17, 40 }));
    ASSERT_EQUAL(t.price, 12550);
    ASSERT_EQUAL(t.arrival_time, (Time{ 20, 33 }));
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestUpdate);
}
