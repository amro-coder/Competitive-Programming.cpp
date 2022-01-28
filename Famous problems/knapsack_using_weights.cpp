#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
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
    int n,w;
    cin>>n>>w;
    vi value(n+1);
    vi weight(n+1);
    for(int i=1;i<n+1;i++){
        cin>>weight[i];
        cin>>value[i];
    }
    ll max_value=n*(*max_element(value.begin()+1, value.end()));
    vector<vl> dp(n+1,(vl (max_value+1, (ll)pow(10,11))));
    for (int i=0;i<=n;i++)
        dp[i][0]=0;

    for (int i=1;i<=n;i++)
        for(int j=1;j<=max_value;j++){
            dp[i][j]=dp[i-1][j];
            if(j-value[i]>=0)
                dp[i][j]=min(dp[i][j],weight[i]+dp[i-1][j-value[i]]);
        }
    int ans;
    for (int i=max_value;i>=0;i--)
        if(dp[n][i]<=w){
            ans=i;
            break;
        }
    cout<<ans<<'\n';
    return 0;
}





