#include "date.h"

Date::Date():
    year(0),
    month(0),
    day(0) {};

Date::Date(
    const int new_year, 
    const int new_month, 
    const int new_day
):
    year(new_year),
    month(new_month),
    day(new_day) {

    if (month < 1 || month > 12) {
        throw std::invalid_argument("Month value is invalid: " + std::to_string(month));
    } else if (day < 1 || day > 31) {
        throw std::invalid_argument("Day value is invalid: " + std::to_string(day));
    }
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}


bool operator==(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return std::make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != std::make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

Date ParseDate(std::istream& input) {
    std::string s;
    input >> s;
    std::stringstream ss(s);

    int year;
    int month;
    int day;
    char delim;


    auto checkInputErr = [s](const std::stringstream& ss, char delim, char symbol) {
        if (ss.fail() || delim != symbol) {
            throw std::invalid_argument("Wrong date format: " + s);
        }
    };

    ss >> year;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> month;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> day;
    if (!ss.eof() || ss.fail()) {
        throw std::invalid_argument("Wrong date format: " + s);
    }

    return Date(year, month, day);
}

std::ostream& operator<<(std::ostream& output, const Date& date) {
    output << std::setfill('0') << std::setw(4) << date.GetYear()
            << '-' << std::setw(2) << date.GetMonth()
            << '-' << std::setw(2) << date.GetDay();

    return output;
}
