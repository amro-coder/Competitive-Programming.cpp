//Problem Statement
//Counting paths in a grid:
//You have a rectangular grid of points with n rows and n columns. You start at the top left corner.
//At each step, you can either go down to the next point in the same column or right to the next point in the same row.
//How many such paths are there from the top left corner to the bottom right corner?
//What if some points are deleted (that is, no path can go through these points)?
//solution using DP:
#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;

#define MP make_pair
// if you want to see the dp
void print(vector<vector<ll>> x){
    for(auto i:x) {
        for (auto j: i)
            cout << j << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,k;
    cin>>n>>m>>k;
    set<pair<int,int>> blocked;
    while (k--) {
        ll x,y;
        cin>>x>>y;
        blocked.insert(MP(x-1,y-1));
    }
    vector<vector<ll>> dp(n+1,vector<ll> (m+1));
    dp[n][m-1]=1;
    for (ll i=n-1;i>=0;i--)
        for (ll j=m-1;j>=0;j--) {
            if (blocked.count(MP(i,j)))
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    cout<<dp[0][0]<<'\n';
    return 0;
}
//you can use combinations for a more efficient solution





