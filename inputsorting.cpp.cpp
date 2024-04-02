#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

struct Person {
    string n
    int id;
    int hour;
    int minute;
    int sleepTime;

    Person(string n, int i, int h, int m, int s) : name(n), id(i), hour(h), minute(m), sleepTime(s) {}
};

bool compareSleepTime(const Person &a, const Person &b) {
    if (a.hour != b.hour)
        return a.hour < b.hour;
    else if (a.minute != b.minute)
        return a.minute < b.minute;
    else
        return a.sleepTime < b.sleepTime;
}

int main() {
    vector<Person> people;

    ifstream infile("inmate.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            stringstream ss(line);
            string name;
            string id_str, hour_str, minute_str, sleepTime_str;

            getline(ss, name, ',');
            getline(ss, id_str, ',');
            getline(ss, hour_str, ',');
            getline(ss, minute_str, ',');
            getline(ss, sleepTime_str, ',');

            int id = stoi(id_str);
            int hour = stoi(hour_str);
            int minute = stoi(minute_str);
            int sleepTime = stoi(sleepTime_str);

            people.push_back(Person(name, id, hour, minute, sleepTime));
        }
        infile.close();
    } 

    sort(people.begin(), people.end(), compareSleepTime);

    ofstream outfile("inmate.txt");
    if (outfile.is_open()) {
        for (const auto &person : people) {
            outfile << person.name << ", " << person.id << ", " << person.hour << ", " << person.minute << ", " << person.sleepTime << endl;
        }
        outfile.close();
    } 

    return 0;
}