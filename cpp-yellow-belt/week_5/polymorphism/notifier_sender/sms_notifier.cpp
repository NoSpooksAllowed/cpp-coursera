#include "sms_notifier.h"
#include "senders.h"

SmsNotifier::SmsNotifier(const std::string& number):
    number_(number) {}

void SmsNotifier::Notify(const std::string& message) const {
   SendSms(number_, message);  
}
