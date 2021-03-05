#pragma once

#include "helpers.h"
#include "date.h"

class Database {
public:
    void Add(const Date& date, const std::string& event);
    
    template<typename P>
    int RemoveIf(const P& predicate) {
        int res = 0;
        
        std::map<Date, std::vector<std::string>> new_storage;
        std::map<Date, std::set<std::string>> new_checker;
        
        for (auto& storage_pair : storage) {
            const auto border = std::stable_partition(storage_pair.second.begin(), storage_pair.second.end(),
                [predicate, storage_pair](const auto& item) {
                    return predicate(storage_pair.first, item);
            });

            const size_t tmp = storage_pair.second.size();

            if (border == storage_pair.second.end()) {
                res += tmp;
            } else {
                new_storage[storage_pair.first] = std::vector<std::string>(border, storage_pair.second.end());
                new_checker[storage_pair.first] = std::set<std::string>(border, storage_pair.second.end());

                res += tmp - new_storage.at(storage_pair.first).size();
            }
        }        

        storage = new_storage;
        checker = new_checker;

        return res;
    }

    template<typename P>
    std::vector<std::pair<Date, std::string>> FindIf(const P& predicate) const {
        std::map<Date, std::vector<std::string>> tmp;
        std::vector<std::pair<Date, std::string>> res;

        for (const auto& storage_pair : storage) {
            std::vector<std::string> tmp_vec;

            std::copy_if(
                storage_pair.second.begin(), 
                storage_pair.second.end(), 
                std::back_inserter(tmp_vec), 
                [predicate, storage_pair](const auto& item) {
                    return predicate(storage_pair.first, item);
                });

            if (tmp_vec.size() != 0) {
                tmp[storage_pair.first] = tmp_vec;
            }
        }

        for (const auto& tmp_pair : tmp) {
            for (const auto& item : tmp_pair.second)  {
                res.push_back(std::make_pair(tmp_pair.first, item));
            }
        }

        return res;
    }

    std::pair<Date, std::string> Last(const Date& date) const;

    void Print(std::ostream& output) const;
private:
    std::map<Date, std::vector<std::string>> storage;
    std::map<Date, std::set<std::string>> checker;
};

std::ostream& operator<<(
    std::ostream& output, 
    const std::pair<Date, 
    std::vector<std::string>>& items);

bool operator<(
    const std::pair<Date, std::string>& lhs, 
    const std::pair<Date, std::string>& rhs);

bool operator==(
    const std::pair<Date, std::string>& lhs, 
    const std::pair<Date, std::string>& rhs);

std::ostream& operator<<(
    std::ostream& output, 
    const std::pair<Date, 
    std::string>& items);
