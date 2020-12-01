#include <iostream>
#include <numeric>
#include <cstdlib>

using namespace std;

class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
        int gcdNum = gcd(abs(numerator), abs(denominator));
        numerator_ = abs(numerator) / gcdNum;
        denominator_ = abs(denominator) / gcdNum;

        if (numerator < 0 && denominator < 0) {
            numerator_ = abs(numerator_);
            denominator_ = abs(denominator_);
        } else if (numerator < 0 || denominator < 0) {
            numerator_ = -numerator_;
            denominator_ = +denominator_;
        }
    }

    int Numerator() const {
        return numerator_;
    }

    int Denominator() const {
        return denominator_;
    }

private:
    long int denominator_;
    long int numerator_;
};

bool operator==(const Rational& lhs, const Rational& rhs) {
    int x1 = lhs.Numerator() * rhs.Denominator();
    int x2 = lhs.Denominator() * rhs.Numerator();

    return x1 == x2;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
    int lcmNum = lcm(lhs.Denominator(), rhs.Denominator());
    int lhsMultiplier = lcmNum / lhs.Denominator();
    int rhsMultiplier = lcmNum / rhs.Denominator();
    
    int numerator = lhs.Numerator() * lhsMultiplier + rhs.Numerator() * rhsMultiplier;
    int denominator = lhs.Denominator() * lhsMultiplier;

    return Rational(numerator, denominator);
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    int lcmNum = lcm(lhs.Denominator(), rhs.Denominator());
    int lhsMultiplier = lcmNum / lhs.Denominator();
    int rhsMultiplier = lcmNum / rhs.Denominator();
    
    int numerator = lhs.Numerator() * lhsMultiplier - rhs.Numerator() * rhsMultiplier;
    int denominator = lhs.Denominator() * lhsMultiplier;

    return Rational(numerator, denominator);

}

Rational operator*(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();

    return Rational(numerator, denominator);
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Numerator();

    return Rational(numerator, denominator);
}

int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
