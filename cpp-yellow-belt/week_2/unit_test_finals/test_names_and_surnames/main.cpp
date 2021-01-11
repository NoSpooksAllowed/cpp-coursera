#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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

class Person {
public:
    void ChangeFirstName(int year, const string& firstName) {
        firstNameData[year] = firstName;
    }

    void ChangeLastName(int year, const string& lastName) {
        lastNameData[year] = lastName;
    }

    string GetFullName(int year) {
        string firstName = GetDataFromMap(year, firstNameData);
        string lastName = GetDataFromMap(year, lastNameData);
    
        if (firstName.size() == 0 && lastName.size() == 0) {
            return "Incognito";
        } else if (firstName.size() == 0) {
            return lastName + " with unknown first name"; 
        } else if (lastName.size() == 0) {
            return firstName + " with unknown last name";
        } else {
            return firstName + " " + lastName;
        }
    }

private:
    map<int, string> firstNameData;
    map<int, string> lastNameData;

    string GetDataFromMap(int year, const map<int, string>& m) {
        int querie = year;

        for (const auto& [key, value] : m) {
            if (key <= year) {
                querie = key;
            }
        }

        if (m.count(querie) == 0) {
            return "";
        } else {
            return m.at(querie);
        }
    }
};

void TestIncognito() {
    {
        Person p;

        AssertEqual(p.GetFullName(2000), "Incognito", "line 146");

        p.ChangeFirstName(1995, "Sergey");
        p.ChangeLastName(1995, "Borisov");

        AssertEqual(p.GetFullName(1990), "Incognito", "line 151");
    }
}

void TestFirstNames() {
    {
        Person p;

        p.ChangeFirstName(1995, "Sergey");
        p.ChangeFirstName(2000, "Andrei");
        p.ChangeFirstName(2010, "Olga");

        AssertEqual(p.GetFullName(1995), "Sergey with unknown last name", "line 163");
        AssertEqual(p.GetFullName(1999), "Sergey with unknown last name", "line 164");
        AssertEqual(p.GetFullName(2000), "Andrei with unknown last name", "line 165");
        AssertEqual(p.GetFullName(2005), "Andrei with unknown last name", "line 166");
        AssertEqual(p.GetFullName(2010), "Olga with unknown last name", "line 167");
        AssertEqual(p.GetFullName(2015), "Olga with unknown last name", "line 168");
    }
}

void TestLastNames() {
    {
        Person p;

        p.ChangeLastName(1995, "Bukovin");
        p.ChangeLastName(2000, "Andreev");
        p.ChangeLastName(2010, "Pukin");

        AssertEqual(p.GetFullName(1995), "Bukovin with unknown first name", "line 180");
        AssertEqual(p.GetFullName(1999), "Bukovin with unknown first name", "line 181");
        AssertEqual(p.GetFullName(2000), "Andreev with unknown first name", "line 182");
        AssertEqual(p.GetFullName(2005), "Andreev with unknown first name", "line 183");
        AssertEqual(p.GetFullName(2010), "Pukin with unknown first name", "line 184");
        AssertEqual(p.GetFullName(2015), "Pukin with unknown first name", "line 185");

    }
}

void TestFullNames() {
    {
        Person p;

        p.ChangeFirstName(1995, "Sergey");
        p.ChangeFirstName(2000, "Andrei");
        p.ChangeFirstName(2010, "Olga");

        p.ChangeLastName(1995, "Bukovin");
        p.ChangeLastName(2000, "Andreev");
        p.ChangeLastName(2010, "Pukin");
 
        AssertEqual(p.GetFullName(1995), "Sergey Bukovin", "line 202");
        AssertEqual(p.GetFullName(1999), "Sergey Bukovin", "line 203");
        AssertEqual(p.GetFullName(2000), "Andrei Andreev", "line 204");
        AssertEqual(p.GetFullName(2005), "Andrei Andreev", "line 205");
        AssertEqual(p.GetFullName(2010), "Olga Pukin", "line 206");
        AssertEqual(p.GetFullName(2015), "Olga Pukin", "line 207");

    }

    {
        Person p;

        p.ChangeFirstName(1995, "Andrei");
        p.ChangeLastName(1995, "Bukovin");
        p.ChangeLastName(1999, "Kukov");
        p.ChangeFirstName(2001, "Sergey");

        AssertEqual(p.GetFullName(1996), "Andrei Bukovin", "line 217");
        AssertEqual(p.GetFullName(2000), "Andrei Kukov", "line 219");
        AssertEqual(p.GetFullName(2002), "Sergey Kukov", "line 221");
    }
}

int main() {
    TestRunner runner;

    runner.RunTest(TestIncognito, "TestIncognito");
    runner.RunTest(TestFirstNames, "TestFirstNames");
    runner.RunTest(TestLastNames, "TestLastNames");
    runner.RunTest(TestFullNames, "TestFullNames");

    return 0;
}
