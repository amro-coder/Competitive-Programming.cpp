//
//You have an array of integers a of size n.
// Initially, all elements of the array are equal to 1.
// You can perform the following operation: choose two integers i (1≤i≤n) and x (x>0), and then increase the value of ai by ⌊aix⌋ (i.e. make ai=ai+⌊aix⌋).
//
//After performing all operations, you will receive ci coins for all such i that ai=bi.
//
//Your task is to determine the maximum number of coins that you can receive by performing no more than k operations.
//
//Input:
// The first line contains a single integer t (1≤t≤100) — the number of test cases.
//
//The first line of each test case contains two integers n and k (1≤n≤10^3;0≤k≤10^6) — the size of the array and the maximum number of operations, respectively.
//
//The second line contains n integers b1,b2,…,bn (1≤bi≤10^3).
//
//The third line contains n integers c1,c2,…,cn (1≤ci≤10^6).
//
//The sum of n over all test cases does not exceed 103.
//
//Output
//For each test case, print one integer — the maximum number of coins that you can get by performing no more than k operations.

//solution:
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long  ll;
typedef vector<ll> vl;

vi minimum_steps(pow(10,3)+1, pow(10,4));
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    minimum_steps[1]=0;
    for (int i=1;i<= pow(10,3);i++){
        for(int j=1;j<=i;j++) {
            auto dest = i + (i / j);
            if(dest<= pow(10,3))
                minimum_steps[dest]=min(minimum_steps[i]+1,minimum_steps[dest]);
        }
    }

    int t;cin>>t;
    while (t--){
        int n,w;
        cin>>n>>w;
        vi b(n+1),values(n+1);
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)cin>>values[i];
        int sum=0;
        for (int i=1;i<=n;i++){
            b[i]=minimum_steps[b[i]];
            sum+=b[i];
        }
        w=min(w,sum);

        vector<vl> dp(n+1,vl(w+1));
        for (int i=1;i<=n;i++)
            if(b[i]==0){
                dp[i][0]=dp[i-1][0]+values[i];
            }
        for (int i=1;i<=n;i++)
            for(int j=0;j<=w;j++){
                dp[i][j]=dp[i-1][j];
                if(b[i]<=j){
                    dp[i][j]=max(dp[i][j],values[i]+dp[i-1][j-b[i]]);
                }
            }
        cout<<dp[n][w]<<'\n';
    }
    return 0;
}
