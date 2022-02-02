#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef vector<ll> vl;


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
    vi values(n),weights(n);
    for (int i=0;i<n;i++){
        cin>>weights[i];
        cin>>values[i];
    }
    vl dp(w+1);
    for (int i=0;i<n;i++)
        for (int j=w;j>=weights[i];j--)
            dp[j]=max(dp[j],dp[j-weights[i]]+values[i]);
    cout<<dp[w]<<'\n';
    // reconstructing solution
    vector<pi> ans;
    int i =w;
    vb visited(n);
    while (i>0){
        bool took_element= false;
        for (int j=0;j<n;j++)
            if((weights[j]<=i)&&(!visited[j])&&(dp[i]==dp[i-weights[j]]+values[j])){
                ans.PB(MP(weights[j], values[j]));
                i -= weights[j];
                visited[j]=true;
                took_element= true;
                break;
            }
        if(!took_element)
            i-=1;
    }
    for(auto i:ans)
        cout<<i.F<<' '<<i.S<<'\n';
    return 0;
}





