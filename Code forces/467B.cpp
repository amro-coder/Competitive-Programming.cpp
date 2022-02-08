//After you had helped George and Alex to move in the dorm, they went to help their friend Fedor play a new computer game «Call of Soldiers 3».
//
//The game has (m+1) players and n types of soldiers in total.
// Players «Call of Soldiers 3» are numbered form 1 to (m+1).
// Types of soldiers are numbered from 0 to n-1.
// Each player has an army. Army of the i-th player can be described by non-negative integer xi.
// Consider binary representation of xi: if the j-th bit of number xi equal to one, then the army of the i-th player has soldiers of the j-th type.
//
//Fedor is the (m+1)-th player of the game.
// He assume that two players can become friends if their armies differ in at most k types of soldiers (in other words, binary representations of the corresponding numbers differ in at most k bits).
// Help Fedor and count how many players can become his friends.

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
    int n,m,k;cin>>n>>m>>k;
    vi x(m+1);
    for(auto &i:x)cin>>i;
    int ans=0;
    for (int i=0;i<m;i++)if(__builtin_popcount(x[m]^x[i])<=k)ans++;
    cout<<ans<<'\n';
    return 0;
}



