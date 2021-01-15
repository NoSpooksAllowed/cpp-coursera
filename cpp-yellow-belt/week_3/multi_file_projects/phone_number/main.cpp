#include <iostream>
#include "phone_number.h"

using namespace std;

int main() {
    try {
        PhoneNumber p("");

        cout << p.GetInternationalNumber() << endl;
    } catch(exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
