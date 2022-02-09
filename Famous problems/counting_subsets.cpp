//Let X = {0...n−1}, and each subset S ⊂ X is assigned an integer value[S].
// Our task is to calculate for each S
//sum(S) =value[A],A⊂S  i.e., the sum of values of subsets of S.

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
    int n;cin>>n;
    vi dp(1<<n);
    for (auto &i:dp)cin>>i;
//  each value represents a subset from its binary form with a set bit i meaning that it contains the element at index i
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            if(j&(1<<i)) dp[j]+=dp[j^(1<<i)];
    print(dp);
    return 0;
}





