void assign(int sleeptimehour,int sleeptimeminute,int asleeptime,string name,int earpodid)
  {
    string y;
    int waitingtime;
    while (1)
    {
        y=checkdorm(q.top().second);
        if (arr[y[0]-65]<capacity) //checks whether the dorm with minimium wait time is full or not
        {
           if (q.top().first.first<sleeptimehour || (q.top().first.first==sleeptimehour && q.top().first.second<=sleeptimeminute))//checks whether the next inmate will have to wait or not
           {
            if(sleeptimeminute+asleeptime>60){//checks whether the hour in clock changes or not
            q.push(make_pair(make_pair(sleeptimehour+1,(sleeptimeminute+asleeptime)%60),q.top().second));//pushes the clock time at which the particular assigned channel will be free
            arr[y[0]-65]++;
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<"."<<endl;
            cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute<<" to "<<sleeptimehour+1<<":"<<(sleeptimeminute+asleeptime)%60<<"."<<endl;
            cout<<"The inmate will fall asleep after this time."<<endl;
            cout<<endl;
            q.pop();//pops out the top element as that clock time is over
            }
            else if(sleeptimeminute+asleeptime<=60){
            q.push(make_pair(make_pair(sleeptimehour,sleeptimeminute+asleeptime),q.top().second));
            arr[y[0]-65]++;
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<"."<<endl;
            cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute<<" to "<<sleeptimehour<<":"<<sleeptimeminute+asleeptime<<"."<<endl;
            cout<<"The inmate will fall asleep after this time."<<endl;
            cout<<endl;
            q.pop();
            }
           }
           else if (q.top().first.first>sleeptimehour || (q.top().first.first==sleeptimehour && q.top().first.second>sleeptimeminute)){
            if(q.top().first.first>sleeptimehour){
            waitingtime=(60-sleeptimeminute)+q.top().first.second;}
            else if(q.top().first.first==sleeptimehour && q.top().first.second>sleeptimeminute){
            waitingtime=q.top().first.second-sleeptimeminute;}
            cout<<name<<" you have to wait for "<<waitingtime<<" minutes"<<endl;
            if(sleeptimeminute+asleeptime+waitingtime>60 || sleeptimeminute+waitingtime>60){
            q.push(make_pair(make_pair(sleeptimehour+1,(sleeptimeminute+asleeptime+waitingtime)%60),q.top().second));
            arr[y[0]-65]++;
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<endl;
            cout<<"The music will be played from "<<sleeptimehour+1<<":"<<(sleeptimeminute+waitingtime)%60<<" to "<<sleeptimehour+1<<":"<<(sleeptimeminute+asleeptime+waitingtime)%60<<"."<<endl;
             cout<<"The inmate will fall asleep after this time."<<endl;
             cout<<endl;
            q.pop();}
            else if(sleeptimeminute+asleeptime+waitingtime<=60){
            q.push(make_pair(make_pair(sleeptimehour,sleeptimeminute+asleeptime+waitingtime),q.top().second));
            arr[y[0]-65]++;
            cout<<"The inmate with name "<<name<<" has been assigned dorm "<<y<<" and his earpod id:"<<earpodid<<" will be assigned to channel id:"<<q.top().second<<endl;
            cout<<"The music will be played from "<<sleeptimehour<<":"<<sleeptimeminute+waitingtime<<" to "<<sleeptimehour<<":"<<sleeptimeminute+asleeptime+waitingtime<<"."<<endl;
             cout<<"The inmate will fall asleep after this time."<<endl;
             cout<<endl;
            q.pop();}
           }
           break;
        }
        else if(arr[y[0]-65]>=capacity)
        {
        q.pop();
        continue;
        }
    }
  }