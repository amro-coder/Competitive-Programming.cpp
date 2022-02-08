//The problem is:
//
//You are given a lucky number n.
// Lucky numbers are the positive integers whose decimal representations contain only the lucky digits 4 and 7.
// For example, numbers 47, 744, 4 are lucky and 5, 17, 467 are not.
//
//If we sort all lucky numbers in increasing order, what's the 1-based index of n?
//
//Tavas is not as smart as SaDDas,
// so he asked you to do him a favor and solve this problem so he can have his headphones back.

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
    string x;
    cin>>x;
    int n=x.size();
    int ans=((1<<(n))-2);
    for(int i=n-1;i>=0;i--)
        if((x[n-1-i]-'0')&1)ans+=(1<<i);
    cout<<ans+1;
    return 0;
}
