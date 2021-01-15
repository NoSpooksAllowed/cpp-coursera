#include "phone_number.h"
#include <stdexcept>
#include <iostream>

PhoneNumber::PhoneNumber(const string& international_number) {
    if (international_number.length() == 0 || international_number[0] != '+') {
        throw invalid_argument("Invalid argument");
    }
    
    size_t country_code_pos;
    for (size_t i = 1; i < international_number.length(); i++) {
        country_code_pos = i;

        if (international_number[i] == '-') {
            break;
        }
        country_code_ += international_number[i];

    }    

    size_t city_code_pos;
    for (size_t i = country_code_pos + 1; i < international_number.length(); i++) {
        city_code_pos = i;

        if (international_number[i] == '-') {
            break;
        }
        city_code_ += international_number[i];

    }

    for (size_t i = city_code_pos + 1; i < international_number.length(); i++) {
        local_number_ += international_number[i];
    }

    if (country_code_.empty() || city_code_.empty() || local_number_.empty()) {
        throw invalid_argument("Invalid argument");
    }
}

auto PhoneNumber::GetCountryCode() const -> string {
    return country_code_;    
}

auto PhoneNumber::GetCityCode() const -> string {
    return city_code_;
}

auto PhoneNumber::GetLocalNumber() const -> string {
    return local_number_;
}

auto PhoneNumber::GetInternationalNumber() const -> string {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
