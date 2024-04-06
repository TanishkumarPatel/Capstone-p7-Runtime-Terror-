#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent a person's detail
struct Person
{
  string name;
  int id;
  int asleepTime;
  int hour;
  int minute;

  // Constructor to initialize the person object
  Person(string n, int i, int s, int h, int m) : name(n), id(i), hour(h), minute(m), asleepTime(s) {}
};

// Comparator function to sort people based on their sleep time or asleep time
bool compareSleepTime(const Person &a, const Person &b)
{
  if (a.hour != b.hour)
    return a.hour < b.hour;
  else if (a.minute != b.minute)
    return a.minute < b.minute;
  else
    return a.asleepTime < b.asleepTime;
}

// Class to manage the sleep induction process/assignment process
class Sleepinducer
{
  int arr[26] = {0}; // Array to keep track of the number of people assigned to each dorm
  int capacity;       // Capacity of each dorm
  vector<string> dormname; // Vector to store dorm names
  vector<string> musicid;  // Vector to store music channel IDs
  priority_queue<pair<pair<int, int>, string>, vector<pair<pair<int, int>, string>>, greater<pair<pair<int, int>, string>>> q; // Priority queue to manage sleep timings for assignment of new input
  unordered_map<string, vector<string>> &musicOptionsPerChannel; // Map to store music options for each channel

public:
  // Constructor to initialize the Sleepinducer object
  Sleepinducer(vector<string> &dormname, vector<string> &music, unordered_map<string, vector<string>> &musicOptions) : dormname(dormname), musicid(music), musicOptionsPerChannel(musicOptions)
  {
    capacity = 5; // Set capacity of each dorm to 5 (can be adjusted)
  }

  // Function to retrieve dorm name based on music channel ID
  string checkdorm(string chid)
  {
    for (int j = 0; j < musicid.size(); j++)
    {
      if (musicid[j] == chid)
      {
        return dormname[j];
      }
    }
  }

  // Function to randomly select a music ID from available options
  string getRandommusicid(vector<string> &musicOptions)
  {
    int randomIndex = rand() % musicOptions.size();
    return musicOptions[rand() % musicOptions.size()];
  }

  // Function to assign the first few inamtes equal to avialable music channels(here according to dorm file first 6 persons will be assigned using this function) the data for sleep induction 
  void assign_first_time(int sleeptimehour, int sleeptimeminute, int asleeptime, string channelid, string name, int earpodid)
  {
    if (sleeptimeminute + asleeptime > 60)
    {
      // If the sleep time exceeds an hour, push the next sleep time to the queue with hour incremented by 1
      q.push(make_pair(make_pair(sleeptimehour + 1, (sleeptimeminute + asleeptime) % 60), channelid));
      string y = checkdorm(channelid);
      arr[y[0] - 65]++; // Increment count of people assigned to the dorm
      cout<<"Inmate Name: "<<name<<endl;
      cout<<"Earpod ID: "<<earpodid<<endl;
      cout<<"Dorm Assigned: "<<y<<endl;
      cout<<"Channel Assigned: "<<channelid<<endl;
      string m = getRandommusicid(musicOptionsPerChannel[channelid]);
      cout<<"Music Assigned: "<<m<<endl;
      cout<<"Music Duration: "<<sleeptimehour<< ":" << sleeptimeminute<< " to " << sleeptimehour + 1 << ":" << (sleeptimeminute + asleeptime) % 60 <<endl;
      cout << endl;
    }
    else if (sleeptimeminute + asleeptime <= 60)
    {
      // If the sleep time does not exceed an hour, push the next sleep time to the queue with hour unchanged
      q.push(make_pair(make_pair(sleeptimehour, sleeptimeminute + asleeptime), channelid));
      string y = checkdorm(channelid);
      arr[y[0] - 65]++;
      cout<<"Inmate Name: "<<name<<endl;
      cout<<"Earpod ID: "<<earpodid<<endl;
      cout<<"Dorm Assigned: "<<y<<endl;
      cout<<"Channel Assigned: "<<channelid<<endl;
      string m = getRandommusicid(musicOptionsPerChannel[channelid]);
      cout<<"Music Assigned: "<<m<<endl;
      cout<<"Music Duration: "<<sleeptimehour<< ":" << sleeptimeminute<< " to " << sleeptimehour << ":" << (sleeptimeminute + asleeptime)<<endl;
      cout << endl;
    }
  }

  // Function to assign sleep induction for subsequent times for a person
  void assign(int sleeptimehour, int sleeptimeminute, int asleeptime, string name, int earpodid)
  {
    string y;
    int waitingtime;
    while (1)
    {
      y = checkdorm(q.top().second);
      if (arr[y[0] - 65] < capacity && q.size()) // Check whether the dorm with minimum wait time is greater or not
      {
        if (q.top().first.first < sleeptimehour || (q.top().first.first == sleeptimehour && q.top().first.second <= sleeptimeminute)) // Check whether the next inmate will have to wait or not
        {
          if (sleeptimeminute + asleeptime > 60)
          {
            q.push(make_pair(make_pair(sleeptimehour + 1, (sleeptimeminute + asleeptime) % 60), q.top().second));
            arr[y[0] - 65]++;
            cout<<"Inmate Name: "<<name<<endl;
            cout<<"Earpod ID: "<<earpodid<<endl;
            cout<<"Dorm Assigned: "<<y<<endl;
            cout<<"Channel Assigned: "<<q.top().second<<endl;
            string m = getRandommusicid(musicOptionsPerChannel[q.top().second]);
            cout<<"Music Assigned: "<<m<<endl;
            cout<<"Music Duration: "<<sleeptimehour<< ":" << sleeptimeminute<< " to " << sleeptimehour + 1 << ":" << (sleeptimeminute + asleeptime) % 60 <<endl;
            cout << endl;
            q.pop();
          }
          else if (sleeptimeminute + asleeptime <= 60)
          {
            q.push(make_pair(make_pair(sleeptimehour, sleeptimeminute + asleeptime), q.top().second));
            arr[y[0] - 65]++;
            cout<<"Inmate Name: "<<name<<endl;
            cout<<"Earpod ID: "<<earpodid<<endl;
            cout<<"Dorm Assigned: "<<y<<endl;
            cout<<"Channel Assigned: "<<q.top().second<<endl;
            string m = getRandommusicid(musicOptionsPerChannel[q.top().second]);
            cout<<"Music Assigned: "<<m<<endl;
            cout<<"Music Duration: "<<sleeptimehour<< ":" << sleeptimeminute<< " to " << sleeptimehour << ":" << (sleeptimeminute + asleeptime) <<endl;
            cout << endl;
            q.pop();
          }
        }
        else if (q.top().first.first > sleeptimehour || (q.top().first.first == sleeptimehour && q.top().first.second > sleeptimeminute))
        {
          if (q.top().first.first > sleeptimehour)
          {
            waitingtime = (60 - sleeptimeminute) + q.top().first.second;
          }
          else if (q.top().first.first == sleeptimehour && q.top().first.second > sleeptimeminute)
          {
            waitingtime = q.top().first.second - sleeptimeminute;
          }
          if (sleeptimeminute + asleeptime + waitingtime > 60 || sleeptimeminute + waitingtime > 60)
          {
            q.push(make_pair(make_pair(sleeptimehour + 1, (sleeptimeminute + asleeptime + waitingtime) % 60), q.top().second));
            arr[y[0] - 65]++;
            cout<<"Inmate Name: "<<name<<endl;
            cout<<"Earpod ID: "<<earpodid<<endl;
            cout<<"Dorm Assigned: "<<y<<endl;
            cout<<"Channel Assigned: "<<q.top().second<<endl;
            string m = getRandommusicid(musicOptionsPerChannel[q.top().second]);
            cout<<"Music Assigned: "<<m<<endl;
            cout<<"Music Duration: "<<sleeptimehour + 1 << ":" << (sleeptimeminute + waitingtime) % 60 << " to " << sleeptimehour + 1 << ":" << (sleeptimeminute + asleeptime + waitingtime) % 60 <<endl;
            cout<<"Waiting time: "<<waitingtime<<" minutes"<<endl;
            cout << endl;
            q.pop();
          }
          else if (sleeptimeminute + asleeptime + waitingtime <= 60)
          {
            q.push(make_pair(make_pair(sleeptimehour, sleeptimeminute + asleeptime + waitingtime), q.top().second));
            arr[y[0] - 65]++;
            cout<<"Inmate Name: "<<name<<endl;
            cout<<"Earpod ID: "<<earpodid<<endl;
            cout<<"Dorm Assigned: "<<y<<endl;
            cout<<"Channel Assigned: "<<q.top().second<<endl;
            string m = getRandommusicid(musicOptionsPerChannel[q.top().second]);
            cout<<"Music Assigned: "<<m<<endl;
            cout<<"Music Duration: "<<sleeptimehour << ":" << (sleeptimeminute + waitingtime)  << " to " << sleeptimehour  << ":" << (sleeptimeminute + asleeptime + waitingtime)  <<endl;
            cout<<"Waiting time: "<<waitingtime<<" minutes"<<endl;
            cout << endl;
            q.pop();
          }
        }
        break;
      }
      else if (arr[y[0] - 65] >= capacity && q.size()) //if the returned dorm name has become full
      {
        q.pop();
        continue;
      }
      else //when the input is greater than the total capacity of dorms
      {
        cout << "WARNING: The dorms are full and no more inmates can be accommodated" << endl;
        break;
      }
    }
  }
};

// Main function
int main()
{
  // Variables to store data
  vector<string> inmate_name;
  vector<string> earpod_id;
  vector<string> time_taken_to_fall_asleep;
  vector<vector<pair<string, string>>> timeData;
  vector<string> dorm_name;
  vector<string> music_channels_id;
  unordered_map<string, vector<string>> musicOptionsPerChannel;

  // Read inmate data from file
  ifstream input("inmate.txt");
  string perticularline;
  while (getline(input, perticularline))
  {
    istringstream iss(perticularline);
    string name, earpod, asleeptime;
    vector<pair<string, string>> dayData;
    getline(iss, name, ',');
    getline(iss, earpod, ',');
    getline(iss, asleeptime, ',');
    inmate_name.push_back(name);
    earpod_id.push_back(earpod);
    time_taken_to_fall_asleep.push_back(asleeptime);
    string token;
    while (getline(iss, token, ','))
    {
      string hour = token.substr(0, 2), minute = token.substr(3, 2);
      dayData.push_back(make_pair(hour, minute));
    }
    timeData.push_back(dayData);
  }

  // Read dorm data from file
  ifstream infile("dorm.txt");
  string line;
  while (getline(infile, line))
  {
    istringstream iss(line);
    string dormName;
    string channelID, musicOption;
    vector<string> musicOptions;

    getline(iss, dormName, ',');
    getline(iss, channelID, ',');
    dorm_name.push_back(dormName);
    music_channels_id.push_back(channelID);

    while (getline(iss, musicOption, ','))
    {
      musicOptions.push_back(musicOption);
    }
    musicOptionsPerChannel[channelID] = musicOptions;
  }
  
  char str[][10]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
  int k = 0;
  while (k < 7) // Loop for each day
  {
    cout << str[k] <<":-"<< endl<<endl;
    vector<Person> people;
    for (int z = 0; z < inmate_name.size(); z++) // Create Person objects and store in vector
    {
      people.push_back(Person(inmate_name[z], stoi(earpod_id[z]), stoi(time_taken_to_fall_asleep[z]), stoi(timeData[z][k].first), stoi(timeData[z][k].second)));
    }
    sort(people.begin(), people.end(), compareSleepTime); // Sort people based on sleep time and asleep time

    int i;
    Sleepinducer obj(dorm_name, music_channels_id, musicOptionsPerChannel);
    for (i = 0; i < music_channels_id.size(); i++)
    {
      obj.assign_first_time(people[i].hour, people[i].minute, people[i].asleepTime, music_channels_id[i], people[i].name, people[i].id); // Assign data for people equal to number of channels ids first
    }
    for (int j = i; j < inmate_name.size(); j++)
    {
      obj.assign(people[j].hour, people[j].minute, people[j].asleepTime, people[j].name, people[j].id); // Assign data for the rest
    }
    k++;
  }
  return 0;
}
