#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

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

void TestBaseRationalConstructor() {
    Rational r;

    AssertEqual(r.Numerator(), 0, "line 209");
    AssertEqual(r.Denominator(), 1, "line 210");
}

void TestFractionReduction() {
    {
        Rational r(15, 20);
        
        AssertEqual(r.Numerator(), 3, "line 216");
        AssertEqual(r.Denominator(), 4, "line 218");
    }

    {
        Rational r(4, 16);

        AssertEqual(r.Numerator(), 1, "line 224");
        AssertEqual(r.Denominator(), 4, "line 225");
    }

    {
        Rational r(-4, 16);

        AssertEqual(r.Numerator(), -1, "line 238");
        AssertEqual(r.Denominator(), 4, "line 239");
    }
}

void TestNegativeRational() {
    {
        Rational r(-4, 16);

        AssertEqual(r.Numerator(), -1, "line 247");
        AssertEqual(r.Denominator(), 4, "line 248");
    }

    {
        Rational r(4, -16);

        AssertEqual(r.Numerator(), -1, "line 254");
        AssertEqual(r.Denominator(), 4, "line 255");
    }

    {
        Rational r(-15, 20);
        
        AssertEqual(r.Numerator(), -3, "line 216");
        AssertEqual(r.Denominator(), 4, "line 218");
    }

    {
        Rational r(15, -20);
        
        AssertEqual(r.Numerator(), -3, "line 216");
        AssertEqual(r.Denominator(), 4, "line 218");
    }

}

void TestPositiveRational() {
    {
        Rational r(-2, -3);

        AssertEqual(r.Numerator(), 2, "line 292");
        AssertEqual(r.Denominator(), 3, "line 293");
    }

    {
        Rational r(10, 10);

        AssertEqual(r.Numerator(), 1, "line 299");
        AssertEqual(r.Denominator(), 1, "line 300");
    }

    {
        Rational r(-5, -15);

        AssertEqual(r.Numerator(), 1, "line 306");
        AssertEqual(r.Denominator(), 3, "line 307");
    }
}

void TestNumeratorNull() {
    {
        Rational r(0, 89);

        AssertEqual(r.Numerator(), 0, "line 315");
        AssertEqual(r.Denominator(), 1, "line 316");
    }

    {
        Rational r(0, 100);

        AssertEqual(r.Numerator(), 0, "line 322");
        AssertEqual(r.Denominator(), 1, "line 323");
    }
}

int main() {
    TestRunner runner;

    runner.RunTest(TestBaseRationalConstructor, "TestBaseRationalConstructor");
    runner.RunTest(TestFractionReduction, "TestFractionReduction");
    runner.RunTest(TestNegativeRational, "TestNegativeRational");
    runner.RunTest(TestNumeratorNull, "TestNumeratorNull");
    runner.RunTest(TestPositiveRational, "TestPositiveRational");

    return 0;
}
