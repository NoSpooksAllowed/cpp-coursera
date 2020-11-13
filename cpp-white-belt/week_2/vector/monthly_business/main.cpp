#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void addPlannerCase(vector<vector<string>>& planner);
void dumpPlannerCase(vector<vector<string>>& planner);
void switchToNextMonth(vector<vector<string>>& planner, int months[], int currentMonth);

int main() {
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> planner(months[0]);
    int currentMonth = 0;

    int numOfOperations;

    cin >> numOfOperations;

    for (int i = 0; i < numOfOperations; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            addPlannerCase(planner);
        } else if (command == "DUMP") {
            dumpPlannerCase(planner);
        } else if (command == "NEXT") {
            currentMonth = (currentMonth + 1) % 12;
            switchToNextMonth(planner, months, currentMonth);
        }
    }
}

void addPlannerCase(vector<vector<string>>& planner) {
    int i;
    cin >> i;
    string s;
    cin >> s;
    i--;
    planner[i].push_back(s); 
}

void dumpPlannerCase(vector<vector<string>>& planner) {
    int i;
    cin >> i;
    i--;
    
    cout << planner[i].size() << " ";

    for (auto elem : planner[i]) {
        cout << elem << " ";
    }

    cout << endl;
}

void switchToNextMonth(vector<vector<string>>& planner, int months[], int currentMonth) {
    vector<vector<string>> tmp(months[currentMonth]);
    
    for (int i = 0; i < static_cast<int>(tmp.size()) && i < static_cast<int>(planner.size()); i++) {
        tmp[i] = planner[i];
    }

    for (int i = months[currentMonth]; i < static_cast<int>(planner.size()); i++) {
        tmp[tmp.size() - 1].insert(end(tmp[tmp.size() - 1]), begin(planner[i]), end(planner[i]));
    }

    planner = tmp;
}
