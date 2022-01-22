//problem Statement:
//Given two strings, find the longest subsequence common both of them.
//This problem differs from problems of finding common substrings:
//unlike substrings, subsequences are not required to occupy consecutive positions within the original sequences
//
//solution:
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
    //reconstruct solution
    string subsequence="";
    int i=0,j=0;
    while (true){
        if(i>=n or j>=m)
            break;
        if(s1[i]==s2[j]) {
            subsequence.PB(s1[i]);
            i++;
            j++;
        }
        else{
            if(dp[i+1][j]>dp[i][j+1])
                i++;
            else
                j++;
        }

    }
    cout<<ans<<'\n'<<subsequence;

    return 0;
}





