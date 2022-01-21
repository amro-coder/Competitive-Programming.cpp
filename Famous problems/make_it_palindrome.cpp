// problem statement:
//t is the number of test cases.
//in each test case you are given a string
//in one opreation you can insert a character at any place
//what are the minimum number of opreatins to make the string palindrome
//palindrome string is a string that reads backword the same it reads forward

//solution:
#include "array"
#include "string"
#include <bits/stdc++.h>
using namespace std;

array<array<int,6105>,6105> dp{};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--){
        string s;
        cin>>s;
        auto n=s.size();
        for (auto i:dp)
            i.fill(0);
        for (int diff=0;diff<n;diff++){
            for (int i=1;i<=n-diff;i++){
                if(s[i-1]==s[i+diff-1])
                    dp[i][i+diff]=dp[i+1][i+diff-1];
                else
                    dp[i][i+diff]=min(dp[i][i+diff-1]+1,dp[i+1][i+diff]+1);
            }
        }
        cout<<dp[1][n]<<'\n';
    }

    return 0;
}





