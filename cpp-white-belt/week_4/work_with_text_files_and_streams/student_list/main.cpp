#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    string surname;
    int day;
    int month;
    int year;
};

int main() {
    vector<Student> students;
    int n, m;
    string operationName;

    cin >> n;

    for (int i = 0; i < n; i++) {
        Student student;
        cin >> student.name;
        cin >> student.surname;
        cin >> student.day;
        cin >> student.month;
        cin >> student.year;

        students.push_back(student);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        unsigned itemNum;
        cin >> operationName;
        cin >> itemNum;
        
        itemNum--;

        if (operationName == "name" && itemNum < students.size()) {
            cout << students[itemNum].name << " " << students[itemNum].surname << endl; 
        } else if (operationName == "date" && itemNum < students.size()) {
            cout << students[itemNum].day << "." << students[itemNum].month << "." << students[itemNum].year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
