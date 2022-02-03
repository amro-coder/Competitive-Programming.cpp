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

vi prefix_sum(int n,vi x){
    vi ans(n+1);
    for(int i=0;i<n;i++)
        ans[i+1]=x[i]+ans[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    vi x(n);for(auto &i:x)cin>>i;
    vi prefix= prefix_sum(n,x);
    int i,j;cin>>i>>j;
//  i is included but j is not
    cout<<prefix[j]- prefix[i];
    return 0;
}





