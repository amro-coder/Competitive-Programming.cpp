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
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vi> dp(n+1,vi(m+1));
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int i=1;i<=m;i++)
        dp[0][i]=i;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            int change_cost=1;
            if(s1[i-1]==s2[j-1])
                change_cost=0;
            dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+change_cost});
        }
    cout<<dp[n][m]<<'\n';
//  reconstruct solution:
    int i=n,j=m;
    vector<string> ans;
    while (i>0 && j>0){
        int change_cost=1;
        if(s1[i-1]==s2[j-1])
            change_cost=0;
        if(dp[i-1][j]+1==min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+change_cost})) {
            //insert char s2[j] in s1
            ans.PB("delete "+ s1.substr(i-1,1) +" in index "+ to_string(i));
            i--;
        } else if(dp[i][j-1]+1==min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+change_cost})) {
            //insert char s2[j] in s1
            ans.PB("insert "+ s2.substr(j-1,1) +" after index "+ to_string(i));
            j--;
        } else {
            if (change_cost == 1) {
                //chenge s1[i] to s2[j]
                ans.PB("change " + s1.substr(i-1,1) + " in index " + to_string(i) + " to " + s2.substr(j-1,1) + " in index " + to_string(j));
            }
            i--;
            j--;
        }

    }
    for (auto i:ans)
        cout<<i<<'\n';
    return 0;
}
