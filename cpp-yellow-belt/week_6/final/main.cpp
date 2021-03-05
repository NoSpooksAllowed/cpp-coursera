#include "helpers.h"
#include "test_db.h"
#include "date.h"
#include "database.h"
#include "node.h"
#include "condition_parser.h"

std::string ParseEvent(std::istream& is);
void TestParseEvent();
void TestAll();
void TestParseDate();

int main() {
    TestAll();

    Database db;

    for (std::string line; getline(std::cin, line);) {
        std::istringstream is(line);

        std::string command;
        is >> command;
        if (command == "Add") {
            const auto date = ParseDate(is);
            const auto event = ParseEvent(is);
            db.Add(date, event);
        } else if (command == "Print") {
            db.Print(std::cout);
        } else if (command == "Del") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date &date, const std::string &event) {
                return condition->Evaluate(date, event);
            };
            int count = db.RemoveIf(predicate);
            std::cout << "Removed " << count << " entries" << std::endl;
        } else if (command == "Find") {
            auto condition = ParseCondition(is);
            auto predicate = [condition](const Date &date, const std::string &event) {
                return condition->Evaluate(date, event);
            };

            const auto entries = db.FindIf(predicate);
            for (const auto &entry : entries) {
                std::cout << entry << std::endl;
            }
            std::cout << "Found " << entries.size() << " entries" << std::endl;
        } else if (command == "Last") {
            try {
                std::cout << db.Last(ParseDate(is)) << std::endl;
            } catch (std::invalid_argument &) {
                std::cout << "No entries" << std::endl;
            }
        } else if (command.empty()) {
            continue;
        } else {
            throw std::logic_error("Unknown command: " + command);

        }
    }

    return 0;
}


std::string ParseEvent(std::istream& is) {
    std::string event;
    std::getline(is >> std::ws, event);

    return event;
}

void TestParseEvent() {
    {
        std::istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Error line 24");
    }
    {
        std::istringstream is("    sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Error line 28");
    }

    {
        std::istringstream is("   first event  \n   second event");
        
        std::vector<std::string> res;
        res.push_back(ParseEvent(is));
        res.push_back(ParseEvent(is));
        std::vector<std::string> expected = {"first event  ", "second event"};

        AssertEqual(res, res, "Error line 37");
    }
    
}

void TestParseDate() {
    {
        std::istringstream is("2017-06-01");

        AssertEqual(ParseDate(is), Date(2017, 6, 1), "Error line 49");
    }

    {
        std::istringstream is("2017-07-08");

        AssertEqual(ParseDate(is), Date(2017, 7, 8), "Error line 56");
    }

    {
        std::istringstream is("2017-07-10");

        AssertEqual(ParseDate(is), Date(2017, 7, 10), "Error line 62");
    }
}

void TestAll() {
    TestRunner tr;

    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestParseDate, "TestParseDate");
    tr.RunTest(TestParseCondition, "TestParseCondition");
    tr.RunTest(TestEmptyNode, "Тест 2 из Coursera");
    tr.RunTest(TestDbAdd, "Тест 3(1) из Coursera");
    tr.RunTest(TestDbFind, "Тест 3(2) из Coursera");
    tr.RunTest(TestDbLast, "Тест 3(3) из Coursera");
    tr.RunTest(TestDbRemoveIf, "Тест 3(4) из Coursera");
    tr.RunTest(TestInsertionOrder, "Тест на порядок вывода");
    tr.RunTest(TestsMyCustom, "Мои тесты");
    tr.RunTest(TestDatabase, "Тест базы данных с GitHub");
}
