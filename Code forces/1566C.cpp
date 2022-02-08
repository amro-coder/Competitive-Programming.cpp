//A binary string is a string that consists of characters 0 and 1.
// A bi-table is a table that has exactly two rows of equal length, each being a binary string.
//
//Let MEX of a bi-table be the smallest digit among 0, 1, or 2 that does not occur in the bi-table.
// For example, MEX for [00111010] is 2, because 0 and 1 occur in the bi-table at least once.
// MEX for [111111] is 0, because 0 and 2 do not occur in the bi-table, and 0<2.
//
//You are given a bi-table with n columns.
// You should cut it into any number of bi-tables (each consisting of consecutive columns) so that each column is in exactly one bi-table.
// It is possible to cut the bi-table into a single bi-table — the whole bi-table.
//
//What is the maximal sum of MEX of all resulting bi-tables can be?

//solution:
#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;


#define F first
#define S second
#define PB push_back
#define MP make_pair

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while (t--){
        int n;cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int ans=0;
        bitset<2> count;
        for(int i=0;i<n;i++){
            if(count[0]&count[1]){
                ans+=2;
                count.reset();
            } else{
                if((count[0])&&(!((s1[i]-'0')&(s2[i]-'0')))){
                    ans+=1;
                    count.reset();
                }}
            count[s1[i]-'0']=1;
            count[s2[i]-'0']=1;
        }
        if(count[0]) {
            if (count[1])
                ans += 2;
            else
                ans+=1;
        }
        cout<<ans<<'\n';


    }
    return 0;
}


