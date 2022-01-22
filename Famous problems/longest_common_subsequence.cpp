#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define F first
#define S second
#define PB push_back
#define MP make_pair
void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int n=s1.size();
    int m=s2.size();
    int ans=0,index=0;
    vector<vector<int>> dp(n+1,vector<int>(m+1));
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--) {
            dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            if(s1[i]==s2[j])
                dp[i][j]=dp[i+1][j+1]+1;
            if(dp[i][j]>ans){
                ans=dp[i][j];
                index=i;
            }
        }
    }
    cout<<ans<<'\n'<<s1.substr(index,ans);

    return 0;
}





