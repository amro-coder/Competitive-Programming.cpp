// problem statement:
// 1- calculate the minimum number of coins to reach a given sum
// 2- how many different ways to get the given sum
// note we can use the coins any number of times
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
    int target,n;
    cin>>n>>target;
    vi coins(n);
    for(auto &i:coins)cin>>i;
    // problem one

    vi dp(target+1,target+1);
    dp[0]=0;
    for (auto i:coins)
        for(int j=0;j<=target;j++)
            if(j-i>=0)
                dp[j]=min(dp[j],dp[j-i]+1);
    cout<<"problem 1:"<<'\n'<<"number of coins = "<<dp[target]<<'\n';
//  reconstructing a solution
    vi sol;
    int sum=target;
    while (sum>0){
        pi minimum_coin=MP(sum+1,-1);
        for (auto i:coins)
            if(sum-i>=0)
                minimum_coin=min(minimum_coin,MP(dp[sum-i]+1,i));
        sol.PB(minimum_coin.S);
        sum-=minimum_coin.S;
    }
    cout<<"coins: ";
    print(sol);
    // problem 2
    vi dp2(target+1,0);
    dp2[0]=1;
    for (auto i:coins)
        for(int j=0;j<=target;j++)
            if(j-i>=0)
                dp2[j]+=dp2[j-i];
    cout<<"problem 2 :"<<'\n'<<"number of ways = "<<dp2[target]<<'\n';
    return 0;
}





