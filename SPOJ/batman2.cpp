//problem statement:
//In short you need to find 2 increasing sub sequence, one goes to right another one goes to left.
//But they can't have common cells.
//What is the maximum number of cells you can visit?
//
//solution:
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
array<array<array<int,105>,105>,105> dp;
int n;
array<int,105> x;
int sol(int i,int last_inc_index,int last_dec_index){
    if(i>=n)
        return 0;
    if(dp[i][last_inc_index][last_dec_index]==-1) {
        int case1 = 0, case2 = 0, case3;
        if ((last_inc_index==n)||(x[i] > x[last_inc_index]))
            case1 = sol(i + 1, i, last_dec_index) + 1;
        if ((last_dec_index==n)||(x[i] < x[last_dec_index]))
            case2 = sol(i + 1, last_inc_index, i) + 1;
        case3 = sol(i + 1, last_inc_index, last_dec_index);
        dp[i][last_inc_index][last_dec_index] = max({case1, case2, case3});
        return dp[i][last_inc_index][last_dec_index];
    } else {
        return dp[i][last_inc_index][last_dec_index];
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>x[i];
        for(auto &i:dp)
            for(auto &j:i)
                j.fill(-1);
        sol(0,n,n);
        int ans=0;
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                ans=max(ans,dp[0][j][k]);
        cout<<ans<<'\n';
    }
    return 0;
}





