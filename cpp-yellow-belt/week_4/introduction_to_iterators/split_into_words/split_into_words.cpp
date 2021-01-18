//#include "split_into_words.h"
#include <vector>
#include <string>

#include <algorithm>

std::vector<std::string> SplitIntoWords(const std::string& s) {
    std::vector<std::string> res;

    for (auto it = s.begin(); ; ) {
        auto it_space = std::find(it, s.end(), ' ');
        
        res.push_back(std::string(it, it_space));

        if (it_space == s.end()) {
            break;
        }

        it = ++it_space;
    }     

    return res;
}
