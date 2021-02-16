#pragma once
#include <string>

class INotifier {
public:
    virtual void Notify(const std::string& message) const = 0;
};
