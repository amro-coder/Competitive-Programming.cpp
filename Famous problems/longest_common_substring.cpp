//problem Statement:
//Suppose we have two words made up from some letters, such as
//        V = T G A T G G A T C
//W = G T T T G C A C
//        We want to find the longest contiguous sequence of letters (subword) that is contained in both words.
//In this case, the longest common substring is "T G"
//
//Solution
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
            if(s1[i]==s2[j])
                dp[i][j] = dp[i + 1][j+1]+1;
            else
                dp[i][j]=0;
            if(dp[i][j]>ans){
                ans=dp[i][j];
                index=i;
            }
        }
    }
    cout<<ans<<'\n'<<s1.substr(index,ans);

    return 0;
}





