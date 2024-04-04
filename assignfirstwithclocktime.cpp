#include<bits/stdc++.h>
#include<string>
using namespace std;
void assignfirstfewinmates(int sleeptimehour,int sleeptimeminute,int asleeptime,int channelid,string name,int earpodid)
  {
    if(sleeptimeminute+asleeptime>60){
    q.push(make_pair(make_pair(sleeptimehour + 1, (sleeptimeminute + asleeptime) % 60), channelid));
    string y=checkdorm(channelid);
    arr[y[0]-65]++;
    cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<channelid<<"."<<endl;
    cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute<<" to "<<sleeptimehour+1<<":"<<(sleeptimeminute+asleeptime)%60<<"."<<endl;
    cout<<"The inmate will fall asleep after this time."<<endl;
    cout<<endl;
    }
    else if(sleeptimeminute+asleeptime<=60){
      q.push(make_pair(make_pair(sleeptimehour,sleeptimeminute+asleeptime),channelid));
      string y=checkdorm(channelid);
    arr[y[0]-65]++;
    cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<channelid<<"."<<endl;
    cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute<<" to "<<sleeptimehour<<":"<<sleeptimeminute+asleeptime<<"."<<endl;
    cout<<"The inmate will fall asleep after this time."<<endl;
    cout<<endl;
    }
  }