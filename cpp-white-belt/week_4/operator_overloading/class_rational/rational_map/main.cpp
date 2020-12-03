#include <iostream>
#include <numeric>
#include <cstdlib>
#include <sstream>
#include <set>
#include <vector>
#include <map>

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
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
