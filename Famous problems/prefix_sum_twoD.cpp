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
    int n,m;cin>>n>>m;
    vector<vi> x(n,vi(m));
    for (auto &i:x)
        for(auto &j:i)
            cin>>j;

    vector<vi> prefix(n+1,vi(m+1));
    for (int i=1;i<=n;i++) {
        prefix[i]= prefix_sum(m,x[i-1]);
        for (int j=1;j<=m;j++)
            prefix[i][j]+= prefix[i-1][j];
    }
    pi a,b,c,d;
//  al points are included
    cin>>a.F>>a.S>>b.F>>b.S>>c.F>>c.S>>d.F>>d.S;
    cout<<prefix[d.F+1][d.S+1]+prefix[a.F][a.S]-prefix[b.F][b.S+1]-prefix[c.F+1][c.S];
    return 0;
}





