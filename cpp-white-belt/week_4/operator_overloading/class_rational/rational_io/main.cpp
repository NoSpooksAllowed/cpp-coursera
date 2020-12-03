#include <iostream>
#include <numeric>
#include <cstdlib>
#include <sstream>

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

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("0  /   1");
        Rational r;
        input >> r;
        bool equal = r == Rational(0, 1);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4"), input4("5/fail");
        Rational r1, r2, r3, r4;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        input4 >> r4;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational() && r4 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
