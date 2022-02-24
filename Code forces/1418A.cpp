//You are playing a very popular game called Cubecraft.
//Initially, you have one stick and want to craft k torches.
//One torch can be crafted using one stick and one coal.
//exchange 1 stick for x sticks (you lose 1 stick and gain x sticks).
//exchange y sticks for 1 coal (you lose y sticks and gain 1 coal).
//During one trade, you can use only one of these two trade offers.
//You can use each trade offer any number of times you want to, in any order.
//Your task is to find the minimum number of trades you need to craft at least k torches.
//The answer always exists under the given constraints.
//You have to answer t independent test cases.
//
//
//
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

void print(vector<int> x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--) {
        ll x, y, k;
        cin >> x >> y >> k;
        cout << (k + ((k * y + k - 3+x) / (x - 1)))<<"\n";
    }
    return 0;
}

