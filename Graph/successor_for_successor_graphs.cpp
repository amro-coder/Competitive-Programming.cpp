#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
typedef tuple<int,int,int> tup;


#define F first
#define S second
#define PB push_back
#define MP make_pair

const ll INF=(1LL<<60);


// debuging tools
void print(vl x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print(vi x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print_pair(pi x){
    cout<<x.F<<" "<<x.S<<"\n";
}
void print2D(vector<vi> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
void print2D(vector<vl> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
// my code
vector<vi> dp;
int xth_successor(int node,int x){
    int n=floor(log2(x));
    for (int i=n;i>=0;i--)
        if (x>>i&1)
            node=dp[i][node];
    return node;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;// each node must exactly have one child
    vi successor(n);
    for (int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        successor[a]=b;
    }
    int u=1024;// the largest successor we could ask for
    int max_power_of_two= floor(log2(u));
    dp.resize(max_power_of_two+1,vi(n,-1));
//  dp[i][j] represents 2**i successor for node j
    dp[0]=successor;
    for(int i=1;i<=max_power_of_two;i++)
        for (int j=0;j<n;j++)
            dp[i][j]=dp[i-1][dp[i-1][j]];
    cout<<xth_successor(0,1)<<"\n";
    cout<<xth_successor(0,2)<<"\n";
    cout<<xth_successor(0,3)<<"\n";
    cout<<xth_successor(0,4)<<"\n";
    cout<<xth_successor(0,5)<<"\n";
    cout<<xth_successor(0,6)<<"\n";
    cout<<xth_successor(0,7)<<"\n";
    cout<<xth_successor(0,8)<<"\n";
}


