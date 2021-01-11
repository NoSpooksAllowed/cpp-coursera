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

bool IsPalindrom(const string& s) {
    for (unsigned i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}

void TestWhiteSpace() {
    Assert(IsPalindrom(""), "line 107");
    Assert(IsPalindrom(" "), "line 108");
    Assert(IsPalindrom("           "), "line 109");
}

void TestOneChar() {
    Assert(IsPalindrom("X"), "line 113");
    Assert(IsPalindrom("1"), "line 114");
}

void TestPalindrom() {
    Assert(IsPalindrom("madam"), "line 118");
    Assert(IsPalindrom("level"), "line 119");
    Assert(IsPalindrom("wasitacaroracatisaw"), "line 120");
    Assert(IsPalindrom("777777"), "line 121");
    Assert(!IsPalindrom("  lool   "), "line 122");
    Assert(!IsPalindrom("ma dam"), "line 123");
    Assert(!IsPalindrom("Madam"), "line 124");
    Assert(!IsPalindrom("777778"), "line 125");
    Assert(IsPalindrom("101"), "line 126");
}

void TestFirsAndLastSymbols() {
    Assert(!IsPalindrom ("leveL"), "line 130");
    Assert(!IsPalindrom ("Level"), "line 131");
    Assert(!IsPalindrom ("level "), "line 132");
    Assert(!IsPalindrom (" level"), "line 133");
    Assert(IsPalindrom (" level "), "line 134");
    Assert(!IsPalindrom("madaM"), "line 135");
}

void TestWithSpaces () {
    Assert(IsPalindrom("l e v e l"), "line 139");
    Assert(IsPalindrom("l  e  v  e  l"), "line 140");
    Assert(!IsPalindrom(" lev e  l   "), "line 141");
    Assert(!IsPalindrom("mada m"), "line 142");
}

int main() {
    TestRunner runner;
    runner.RunTest(TestWhiteSpace, "TestWhiteSpace");
    runner.RunTest(TestOneChar, "TestOneChar");
    runner.RunTest(TestPalindrom, "TestPalindrom");
    runner.RunTest(TestFirsAndLastSymbols, "TestFirsAndLastSymbols");
    runner.RunTest(TestWithSpaces, "TestWithSpaces");
    return 0;
}
