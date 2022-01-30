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
    int n,start,end;
    cin>>n;
    vector<pi> events;
    for (int i=0;i<n;i++){
        cin>>start>>end;
        events.PB(MP(end,start));
    }
    sort(events.begin(),events.end());
    int last=-1,ans=0;
    for (auto i:events)
        if(i.S>last){
            last=i.F;
            ans+=1;
        }

    cout<<ans;


    return 0;
}





