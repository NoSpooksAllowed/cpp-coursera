#include <iostream>
#include <numeric>
#include <cstdlib>
#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <exception>
#include <cstring>

using namespace std;

class Rational {
public:
    Rational() {
        numerator_ = 0;
        denominator_ = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }

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

    if (denominator == 0) {
        throw domain_error("Division by zero");
    }

    return Rational(numerator, denominator);
}

ostream& operator<<(ostream& outputStream, const Rational& r) {
    outputStream << r.Numerator() << "/" << r.Denominator();

    return outputStream;
}

istream& operator>>(istream& inputStream, Rational& r) {
    int numerator = 0;
    int denominator = 0;
    char op;

    inputStream >> numerator;
    inputStream >> op;
    inputStream >> denominator;    

    if (!inputStream.fail() && op == '/') {
        r = Rational(numerator, denominator);
    } else if(inputStream.fail() && !inputStream.eof()) {
        inputStream.clear();
    } 

    return inputStream;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
    int x1 = lhs.Numerator() * rhs.Denominator();
    int x2 = lhs.Denominator() * rhs.Numerator();

    return x1 < x2;
}

int main() {
    Rational r1, r2;
    char op;


    try {
        cin >> r1 >> op >> r2;
        
        switch (op) {
            case '+': 
                cout << r1 + r2 << endl;
            break;

            case '-': 
                cout << r1 - r2 << endl;
            break;

            case '/':
                cout << r1 / r2 << endl;
            break;

            case '*':
                cout << r1 * r2 << endl;
            break;
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }


    return 0;
}
