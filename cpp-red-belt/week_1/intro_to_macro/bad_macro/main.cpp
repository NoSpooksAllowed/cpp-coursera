#include "test_runner.h"

#include <ostream>

#define PRINT_VALUES(out, x, y) \
    out << (x) << std::endl << (y) << std::endl

int main() {
//    TestRunner tr;
//    tr.RunTest([] {
//        std::ostringstream output;
//        PRINT_VALUES(output, 5, "red belt");
//        ASSERT_EQUAL(output.str(), "5\nred belt\n");
//    }, "PRINT_VALUES usage example");

    std::ostringstream output;
    if (true)
        PRINT_VALUES(output, 5, "red belt");
    else
        PRINT_VALUES(output, 5, "red belt");
}
