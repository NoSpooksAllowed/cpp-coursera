#pragma once
#include <string>

#include "i_notifier.h"

class EmailNotifier : public INotifier {
public:
    EmailNotifier(const std::string& email);

    void Notify(const std::string& message) const override;

private:
    const std::string email_;
};
