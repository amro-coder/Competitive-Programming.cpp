//You are given two binary strings x and y, which are binary representations of some two integers (let's denote these integers as f(x) and f(y)).
// You can choose any integer k≥0, calculate the expression sk=f(x)+f(y)⋅2k and write the binary representation of sk in reverse order (let's denote it as revk).
// For example, let x=1010 and y=11; you've chosen k=1 and, since 21=102, so sk=10102+112⋅102=100002 and revk=00001.
//
//For given x and y, you need to choose such k that revk is lexicographically minimal (read notes if you don't know what does "lexicographically" means).
//
//It's guaranteed that, with given constraints, k exists and is finite.

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
        string s1,s2;cin>>s1>>s2;
        bitset<100000> a(s1);
        bitset<100000> b(s2);
        bitset<100000> c;
        c.set();
        int first_one=b._Find_first();
        for (int i=0;i<first_one;i++)
            c[i]=0;
        cout<<(a&c)._Find_first()-first_one<<'\n';
    }
    return 0;
}
