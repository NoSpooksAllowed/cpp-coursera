#pragma once
#include "i_notifier.h"

class SmsNotifier : public INotifier {
public:
    SmsNotifier(const std::string& number);

    void Notify(const std::string& message) const override;
private:
    const std::string number_;
};
