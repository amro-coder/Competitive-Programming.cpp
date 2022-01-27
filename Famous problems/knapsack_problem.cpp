#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<ll> vl;


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
    int n,w;
    cin>>n>>w;
    vi values(n+1),weights(n+1);
    for (int i=1;i<=n;i++){
        cin>>weights[i];
        cin>>values[i];
    }
    vector<vl> dp(n+1,vl(w+1));
    for (int i=1;i<=n;i++)
        for(int j=1;j<=w;j++){
            dp[i][j]=dp[i-1][j];
            if(weights[i]<=j){
                dp[i][j]=max(dp[i][j],values[i]+dp[i-1][j-weights[i]]);
            }
        }
    cout<<dp[n][w]<<'\n';
//  reconstructing solution
    vector<pi> knapsack;
    int i=n,j=w;
    while (i>0 && j>0){
        if(dp[i][j]!=dp[i-1][j]){
            knapsack.PB(MP(weights[i],values[i]));
            j-=weights[i];
        }
        i-=1;
    }
    for (auto i:knapsack)
        cout<<i.F<<' '<<i.S<<'\n';

    return 0;
}





