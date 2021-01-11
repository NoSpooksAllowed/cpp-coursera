#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <typename T>
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

template <typename T>
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

template <typename K, typename V>
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

template<typename T, typename U>
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
  template <typename TestFunc>
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

int LinearEquationRoot(double b, double c) {
    if (b == 0 && c != 0) {
        return 0;
    }

    return 1;
}

int QuadraticEquationRoot(double a, double b, double c) {
    int d = (b*b) - 4 * a * c;

    if (d > 0) {
        return 2;
    } else if (d == 0) {
        return 1;
    } else {
        return 0;
    }

}

int GetDistinctRealRootCount(double a, double b, double c) {
    if (a == 0) {
        return LinearEquationRoot(b, c);
    }

    return QuadraticEquationRoot(a, b, c);
}

void TestTwoRoots() {
    {
        AssertEqual(GetDistinctRealRootCount(5, 5, 1), 2, "line 109");
    }

    {
        AssertEqual(GetDistinctRealRootCount(10, 100, 10), 2, "line 114");
    }

    {
        AssertEqual(GetDistinctRealRootCount(10, 10, 0), 2, "line 118");
    }

    {
        AssertEqual(GetDistinctRealRootCount(1, 10, 5), 2, "line 122");
    }
}

void TestOneRoot() {
    {
        AssertEqual(GetDistinctRealRootCount(0, 10, 10), 1, "line 128");
    }

    {
        AssertEqual(GetDistinctRealRootCount(1, 10, 25), 1, "line 132");
    }

    {
        AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "line 136");
    }
}

void TestNoRoots() {
    {
        AssertEqual(GetDistinctRealRootCount(10, 0, 10), 0, "line 142");
    }

    {
        AssertEqual(GetDistinctRealRootCount(0, 0, 10), 0, "line 146");
    }

    {
        AssertEqual(GetDistinctRealRootCount(5, 5, 10), 0, "line 150");
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(TestTwoRoots, "TestTwoRoots");
    runner.RunTest(TestOneRoot, "TestOneRoot");
    runner.RunTest(TestNoRoots, "TestNoRoots");
    return 0;
}
