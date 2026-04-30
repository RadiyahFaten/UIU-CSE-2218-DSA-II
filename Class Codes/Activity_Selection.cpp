#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// there has to at least 1 hour gap between two tasks


class Activity{

public:

    string name;
    int st_time;
    int fi_time;


};


bool comp(Activity a1, Activity a2){

return a1.fi_time<a2.fi_time;

}

int main(){


vector<int> start = { 3, 0,5,8,5,1};

vector<int> finish = { 4,6,7,9,9,2 };


vector<Activity> acts;

for(int i =0;i<start.size();i++){

    Activity a;
    a.name = "a" + to_string(i);
    a.st_time= start[i];
    a.fi_time= finish[i];
    acts.push_back(a);



}

sort(acts.begin(),acts.end(),comp);

int cur_time =-1;
int cnt=0;

for(Activity a: acts){

    if(cur_time<=a.st_time+1){

     cur_time=a.fi_time;
     cout<<a.name<<endl;
     cnt++;



    }


}






}
