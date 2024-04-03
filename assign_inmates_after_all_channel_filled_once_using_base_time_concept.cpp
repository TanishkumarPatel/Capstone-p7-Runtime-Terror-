#include<bits/stdc++.h>
#include<string>
using namespace std;
void assign(int sleeptimehour,int sleeptimeminute,int asleeptime,string name,int earpodid,int basetimehour,int basetimeminute)
  {
    string y;
    while (1)
    {
        y=checkdorm(q.top().second);
        if (arr[y[0]-65]<capacity)
        {
            int sleeptime=(sleeptimehour*60+sleeptimeminute)-(basetimehour*60+basetimeminute);//sleeptime is the total time passed from the base time after which the next inmate is having his/her bedtime
           if (q.top().first<=sleeptime)//checks whether the time taken(in mintues counted from base time) by the first channel in the priority queue is greater than or less than the sleeptime
           {
            int channeloccupancytime=sleeptime+asleeptime;//time taken(in minutes counted from base time) by the next inmate to free the particular channel
            q.push(make_pair(channeloccupancytime,q.top().second));
            arr[y[0]-65]++;//increases the bed counter of dorms
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<"."<<endl;
            cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute<<" to "<<basetimehour+(channeloccupancytime/60)<<":"<<channeloccupancytime-(60*(channeloccupancytime/60))<<"."<<endl;
            cout<<"The inmate will fall asleep after this time."<<endl;
            cout<<endl;
            q.pop();
           }
           else if (q.top().first>sleeptime)
           {
            int waitingtime=q.top().first-sleeptime;//waiting time of the particular inmate
            int channeloccupancytime=q.top().first+asleeptime;
            q.push(make_pair(channeloccupancytime,q.top().second));
            arr[y[0]-65]++;
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<" after a waiting time of "<<waitingtime<<" minutes."<<endl;
            cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute+waitingtime<<" to "<<basetimehour+(channeloccupancytime/60)<<":"<<channeloccupancytime-(60*(channeloccupancytime/60))<<"."<<endl;
             cout<<"The inmate will fall asleep after this time."<<endl;
             cout<<endl;
            q.pop();
           }
           break;
        }
        else if (arr[y[0]-65]>=capacity)
        {
           q.pop();
           continue;
        }
    }
  }