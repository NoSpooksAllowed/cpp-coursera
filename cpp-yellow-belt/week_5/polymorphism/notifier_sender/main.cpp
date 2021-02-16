#include <iostream>
#include <string>

#include "senders.h"
#include "sms_notifier.h"
#include "email_notifier.h"
#include "i_notifier.h"

void Notify(INotifier& notifier, const std::string& message);

int main() {
    SmsNotifier sms{"+7-495-777-77-77"};
    EmailNotifier email{"na-derevnyu@dedushke.ru"};

    Notify(sms, "I have White belt in C++");
    Notify(email, "And want a Yellow one");

    return 0;
}

void Notify(INotifier& notifier, const std::string& message) {
    notifier.Notify(message);
}
