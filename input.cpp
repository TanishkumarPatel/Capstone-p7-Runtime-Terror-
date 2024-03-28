#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    vector <string> inmate_name;
    vector <string> earpod_id;
    vector <string> sleep_time;
    vector <string> time_taken_to_fall_asleep;
    vector <string> dorm_name;
    vector <string> music_channels_id;

        ifstream input("inmate.txt");
        string perticularline;
        while(getline(input,perticularline))
        {
            istringstream iss(perticularline);
            string name,earpod,sleeptime,asleeptime;
            if(getline(iss,name,',') and getline(iss,earpod,',') and getline(iss,sleeptime,',') and getline(iss,asleeptime,',') )
            {
                inmate_name.push_back(name);
                earpod_id.push_back(earpod);
                sleep_time.push_back(sleeptime);
                time_taken_to_fall_asleep.push_back(asleeptime);
            }
        }
         
    
        ifstream infile("dorm.txt");
        string line;
        while(getline(infile,line))
        {
            istringstream iss(line);
            string name,channelid;
            if(getline(iss,name,',') and getline(iss,channelid,',') )
            {
                dorm_name.push_back(name);
                music_channels_id.push_back(channelid);
            }
        }
        // cout<<inmate_name[2]<<" ";
        // cout<<earpod_id[2]<<" ";
        // cout<<sleep_time[2]<<" ";
        // cout<<time_taken_to_fall_asleep[2]<<" "<<endl;
        // cout<<dorm_name[5]<<" ";
        // cout<<music_channels_id[5]<<" ";
}