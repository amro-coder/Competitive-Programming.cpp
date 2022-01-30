//Let us now consider a problem where we are given n tasks with durations and
//deadlines and our task is to choose an order to perform the tasks. For each task,
//we earn d − x points where d is the task’s deadline and x is the moment when we
//finish the task. What is the largest possible total score we can obtain?

#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define F first
#define S second
#define PB push_back
#define MP make_pair

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    int duration,deadline,time=0,ans=0;
    vector<pi> tasks;
    while (n--){
        cin>>duration>>deadline;
        tasks.PB(MP(duration,deadline));
    }
    sort(tasks.begin(),tasks.end());
    for(auto i:tasks){
        time+=i.F;
        ans+=(time-i.S);
    }
    cout<<ans;
    return 0;
}





