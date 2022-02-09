//We are given the prices of k products over n days, and we want to buy each product exactly once.
// However, we are allowed to buy at most one product in a day. What is the minimum total price?

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
    int n,k;
    cin>>n>>k;
    vector<vi> products(n,vi(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin>>products[i][j];
    vector<vi> dp(n,vi(1<<k,INT_MAX/2));
    for(int i=0;i<k;i++)
        dp[0][1 << i] = products[0][i];
    for(int i=0;i<n;i++)
        dp[i][0]=0;

    for (int i=1;i<n;i++)
        for(int j=0;j<k;j++)
            for(int s=0;s<(1<<k);s++)
                if(s&(1<<j))
                    dp[i][s]=min({dp[i][s],dp[i-1][s],dp[i-1][s^(1<<j)]+products[i][j]});

    cout<<dp[n-1][(1<<k)-1];
    return 0;
}





