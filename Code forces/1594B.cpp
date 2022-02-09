//Theofanis really likes sequences of positive integers,
// thus his teacher (Yeltsa Kcir) gave him a problem about a sequence that consists of only special numbers.
//
//Let's call a positive number special if it can be written as a sum of different non-negative powers of n.
// For example, for n=4 number 17 is special, because it can be written as 40+42=1+16=17, but 9 is not.
//
//Theofanis asks you to help him find the k-th special number if they are sorted in increasing order.
//Since this number may be too large, output it modulo 109+7.


//solution:
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
    int t;cin>>t;
    while (t--){
        ll n,k;cin>>n>>k;
        ll ans=0;
        ll mod= 1e9+7;
        ll inc=1;
        while (k){
            if(k&1)
                ans += inc;
            inc*=n;
            inc%=mod;
            k>>=1;
            ans%=mod;
        }
        cout<<ans<<'\n';


    }
    return 0;
}
