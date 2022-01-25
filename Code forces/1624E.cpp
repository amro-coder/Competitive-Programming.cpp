//Masha meets a new friend and learns his phone number — s.
//She wants to remember it as soon as possible.
//The phone number — is a string of length m that consists of digits from 0 to 9.
//The phone number may start with 0.
//Masha already knows n phone numbers (all numbers have the same length m).
//It will be easier for her to remember a new number if the s is represented as segments of numbers she already knows.
//Each such segment must be of length at least 2, otherwise there will be too many segments and Masha will get confused.
//
//For example, Masha needs to remember the number: s= '12345678' and she already knows n=4 numbers: '12340219', '20215601', '56782022', '12300678'.
//You can represent s as a 3 segment: '1234' of number one, '56' of number two, and '78' of number three.
//There are other ways to represent s.
//
//Masha asks you for help, she asks you to break the string s into segments of length 2 or more of the numbers she already knows.
//If there are several possible answers, print any of them.
//
//solution:
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
void printVI(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
    cout<<'\n';
}
void print(map<int,vi> x){
    for(auto i:x){
        cout<<i.F<<" {";
        for (auto j:i.S)
            cout<<j<<' ';
        cout<<"}"<<'\n';
    }}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string> phones;
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            phones.PB(temp);
        }
        string s;
        cin>>s;
        s=" "+s;

//      each segment can be genrated by 2 and 3 segements
//      so we only make the two and three segmants
        map<string,pi> twos;
        map<string,pi> threes;
        for(int i=0;i<n;i++){
            for(int j=0;j<m-2;j++) {
                twos[phones[i].substr(j, 2)]=MP(i+1, j+1);
                threes[phones[i].substr(j,3)]=MP(i+1,j+1);
            }
            if(m-2>=0)
                twos[phones[i].substr(m-2, 2)]=MP(i+1, m-1);
        }
        vector<bool> dp(m+1);
        vector<tuple<int,int,int,int>> path(m+1);
        dp[0]=true;
        for (int i=0;i<=m;i++){
            if(dp[i]){
                if(i+2<=m)
                    if(twos[s.substr(i+1,2)].F!=0){
                        dp[i+2]=true;
                        path[i+2]={twos[s.substr(i+1,2)].S,twos[s.substr(i+1,2)].S+1,twos[s.substr(i+1,2)].F,i};
                    }

                if(i+3<=m)
                    if(threes[s.substr(i+1,3)].F!=0){
                        dp[i+3]=true;
                        path[i+3]={threes[s.substr(i+1,3)].S,threes[s.substr(i+1,3)].S+2,threes[s.substr(i+1,3)].F,i};
                    }

            }
        }
        vector<vi> ans;
        int i=m;
        if(dp[m]){
            while (i>0){
                ans.PB({get<0>(path[i]),get<1>(path[i]),get<2>(path[i])});
                i=get<3>(path[i]);
            }
            reverse(ans.begin(),ans.end());
            cout<<ans.size()<<'\n';
            for(auto i:ans)
                printVI(i);

        } else
            cout<<-1<<'\n';
    }

    return 0;
}


