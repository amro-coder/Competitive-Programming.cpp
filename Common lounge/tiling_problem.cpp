//Problem Statement:
//Tiling problem:
//Problem: You are given a grid of size n×2 and n tiles of size 2×1
//In how many different ways can you tile the grid such that the entire grid is covered and no tiles overlap. (The tiles look identical to each other).
//Two ways of tiling are different based on whether the tiles are placed horizontally or vertically.
//Solution:

#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef vector<int> vi;
// if you want to see the DP
void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
// recursion solution O(2^n)
ll number_of_ways(ll n){
    if(n<=1)
        return 1;
    return number_of_ways(n-1)+ number_of_ways(n-2);
}
//dp solution O(n)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vi dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n];
    return 0;
}





