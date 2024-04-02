#include<bits/stdc++.h>
#include<string>
using namespace std;
int main() {
    void assign_first_few_inmates(int sleeptimehour, int sleeptimeminute, int asleeptime, int channelid, string name, int earpodid, int basetimehour, int basetimeminute)
  {
    int elapsedtime = (sleeptimehour * 60 + sleeptimeminute + asleeptime) - (basetimehour * 60 + basetimeminute);// here basetime is the bedtime of first inmate and is used as a reference time for the calculation of other rommate according to our logic
    q.push(make_pair(elapsedtime, channelid));
    string y = checkdorm(channelid);
    arr[y[0] - 65]++;//dorm names to be used int the format A,B,C,etc because counter is stored as y-65
    cout << "The inmate with name " << name << " has been assigned dorm " << y << " and his earpod id:" << earpodid << " will be assigned to channel id:" << channelid << "." << endl;
    (sleeptimeminute+asleeptime<60)?(cout << "The music will be played from " << sleeptimehour << ":" << sleeptimeminute << " to " << sleeptimehour << ":" <<sleeptimeminute+asleeptime<< "." << endl):(cout << "The music will be played from " << sleeptimehour << ":" << sleeptimeminute << " to " << sleeptimehour+((sleeptimeminute+asleeptime)/60) << ":" << ((sleeptimeminute+asleeptime)-60) << "." << endl);
    cout << "The inmate will fall asleep after this time." << endl;
    cout << endl;
  }
       return 0;
}