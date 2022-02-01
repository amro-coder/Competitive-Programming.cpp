// greedy version of the coin problem
// notice each coin can be constructed from coins less than it
#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,target;
    cin>>n>>target;
    vi coins(n);
    for (auto &i:coins)cin>>i;
    sort(coins.rbegin(),coins.rend());
    int ans=0;
    int i=0;
    while (target>0){
        ans+=(target/coins[i]);
        target-=(target/coins[i])*coins[i];
        i++;
    }
    cout<<ans;

    return 0;
}





