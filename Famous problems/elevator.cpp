//There is an elevator with maximum weight x, and n people with known weights who want to get from the ground floor to the top floor.
// What is the minimum number of rides needed if the people enter the elevator in an optimal order?

// solution:
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
void printvp(vector<pi> x){
    for(auto i:x)
        cout<<i.F<<' '<<i.S<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;cin>>n>>x;
    vi weights(n);
    for(auto &i:weights)cin>>i;
    vector<pi> optimized_dp(1<<n,MP(n+1,0));
    optimized_dp[0]=MP(1,0);
    for (int i=1;i<(1<<n);i++)
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                pi option=optimized_dp[i^(1<<j)];
                if(weights[j]+option.S<=x)
                    option.S+=weights[j];
                else{
                    option.F++;
                    option.S=weights[j];
                }
                optimized_dp[i]=min(optimized_dp[i],option);
            }
        }
    cout<<optimized_dp[(1<<n)-1].F<<' '<<optimized_dp[(1<<n)-1].S<<'\n';
    return 0;
}





