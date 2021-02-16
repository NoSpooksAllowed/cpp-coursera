#include "email_notifier.h"
#include "senders.h"

EmailNotifier::EmailNotifier(const std::string& email):
    email_(email) {}

void EmailNotifier::Notify(const std::string& message) const {
    SendEmail(email_, message);
}
