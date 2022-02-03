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
    int m;
    cin>>m;
    vi x(m);
    for(auto &i:x)cin>>i;
    int n=log2(m);
    vector<vi> dp(n+1,vi(m));
    dp[0]=x;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++) {
            if(j+(pow(2,i)-1)<m)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j+pow(2, i - 1)]);
        }

    int q;cin>>q;
    while (q--){
        int a,b;cin>>a>>b;
//      a and b are included
        int length=b-a+1;
        int inc= log2(length);
        cout<<min(dp[inc][a],dp[inc][b-(pow(2,inc)-1)])<<'\n';
    }
    return 0;
}





