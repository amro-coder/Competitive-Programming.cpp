//Danik urgently needs rock and lever! Obviously, the easiest way to get these things is to ask Hermit Lizard for them.
//
//Hermit Lizard agreed to give Danik the lever. But to get a stone, Danik needs to solve the following task.
//
//You are given a positive integer n, and an array a of positive integers.
// The task is to calculate the number of such pairs (i,j) that i<j and ai & aj≥ai⊕aj, where & denotes the bitwise AND operation, and ⊕ denotes the bitwise XOR operation.
//Danik has solved this task. But can you solve it?


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
        int n;cin>>n;
        vi x(n);
        for(auto &i:x)cin>>i;
        vector<ll> count(33);
        ll zeros=0;
        for (auto i:x)
            if(i!=0)
                count[__builtin_clz(i)]++;
            else
                zeros++;
        ll ans=zeros*(zeros-1)/2;
        for (auto i:count)
            ans+=i*(i-1)/2;
        cout<<ans<<'\n';
    }
    return 0;
}





