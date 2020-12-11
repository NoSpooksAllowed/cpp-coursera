#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iomanip>
#include <exception>
#include <sstream>

using namespace std;

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int newYear, int newMonth, int newDay) {
        year = newYear;

        if (newMonth < 1 || newMonth > 12) {
            throw invalid_argument("Month value is invalid: " + to_string(newMonth));
        } else if (newDay < 1 || newDay > 31) {
            throw invalid_argument("Day value is invalid: " + to_string(newDay));
        }
        month = newMonth;
        day = newDay;
    }

    int GetYear() const {
        return year;
    };

    int GetMonth() const {
        return month;
    };

    int GetDay() const {
        return day;
    };

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

istream& operator>>(istream& input, Date& date) {
    string s;
    input >> s;
    stringstream ss(s);

    int year;
    int month;
    int day;
    char delim;

    
    auto checkInputErr = [s](const stringstream& ss, char delim, char symbol) {
        if (ss.fail() || delim != symbol) {
            throw invalid_argument("Wrong date format: " + s); 
        }
    };

    ss >> year;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> month;
    ss >> delim;
    checkInputErr(ss, delim, '-');
    ss >> day;
    if (!ss.eof() || ss.fail()) {
        throw invalid_argument("Wrong date format: " + s);
    }

    date = Date(year, month, day);

    return input;
}

ostream& operator<<(ostream& output, const Date& date) {
    output << setfill('0') << setw(4) << date.GetYear() 
            << '-' << setw(2) << date.GetMonth() 
            << '-' << setw(2) << date.GetDay();

    return output;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        database[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (database[date].count(event) > 0) {
            database[date].erase(event);

            return true;
        } else {
            return false;
        }
    }
    int DeleteDate(const Date& date) {
        if (database[date].size() > 0) {
            int res = database[date].size();

            database[date].clear();

            return res;
        } else {
            return 0;
        }
    }

    void Find(const Date& date) const {
        if (database.count(date) > 0) {
            const auto& events = database.at(date);

            for (const auto& event : events) {
                cout << event << endl;
            }

        }
    };
  
    void Print() const {
        for (const auto&[key, value] : database) {
            for (const auto& event : value) {
                cout << key << " " <<  event << endl;
            }
        }
    };

private:
    map<Date, set<string>> database;
};

int main() {
    Database db;
    Date d;
    string command;
    try {
        while (cin >> command) {
            if (command == "Add") {
                cin >> d;
                string event;
                cin >> event;

                db.AddEvent(d, event);
            
            } else if (command == "Del") {
                string s;
                getline(cin, s);
                stringstream input(s);
                input >> d;
                if (input.eof()) {
                    cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
                } else {
                    string event;
                    input >> event;

                    (db.DeleteEvent(d, event)) ? cout << "Deleted successfully" << endl : cout << "Event not found" << endl;
                }
            } else if (command == "Find") {
                cin >> d;

                db.Find(d);
            } else if (command == "Print") {
                db.Print();
            } else {
                throw invalid_argument("Unknown command: " + command);
            }
        }
    } catch(exception& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
