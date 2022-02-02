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

void print(vl x){
    for(auto i:x)
        cout<<i<<' ';
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,w;
    cin>>n>>w;
    vi value(n);
    vi weight(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
        cin>>value[i];
    }
    int max_value=n*(*max_element(value.begin(), value.end()));
    vl dp(max_value+1, LONG_LONG_MAX/2);
    dp[0]=0;
    for (int i=0;i<n;i++)
        for (int j=max_value;j>=value[i];j--)
            dp[j]=min(dp[j],dp[j-value[i]]+weight[i]);
    int ans=max_value-(find_if(dp.rbegin(),dp.rend(),[w](ll x){return x<=w;})-dp.rbegin());
    cout<<ans<<'\n';
//  reconstruct solution:
    vector<pi> solution;
    int i =ans;
    vb visited(n);
    while (i>0) {
        for (int j = 0; j < n; j++)
            if ((value[j] <= i) && (!visited[j]) && (dp[i] == dp[i - value[j]] + weight[j])) {
                solution.PB(MP(weight[j], value[j]));
                i -= value[j];
                visited[j] = true;
                break;
            }}
    for (auto i: solution)
        cout << i.F << ' ' << i.S << '\n';
    return 0;

}





