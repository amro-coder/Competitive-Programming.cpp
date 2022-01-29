#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
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
vi x;
vi ans;
vector<vi> combs;
void all_comb_rec(int index){
    if(index>=x.size()) {
        combs.PB(ans);
        // do some logic to combination
        return ;
    }
// if you dont take element
    all_comb_rec(index+1);
// if you take element
    ans.PB(x[index]);
    all_comb_rec(index+1);
    ans.pop_back();
    return;
}

void all_comb_bin(int n){
    for (int i=0;i<(1<<n);i++){
        vi subset;
        for (int j=0;j<n;j++)
            if(1&(i>>j))subset.PB(x[j]);
        combs.PB(subset);
    }}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    x.resize(n);
    for (auto &i:x)cin>>i;
//    all_comb_rec(0);
    all_comb_bin(n);
    sort(combs.begin(),combs.end(),[](vi x,vi y){pi a=MP(x.size(),0); pi b=MP(y.size(),0);if(!x.empty())a.S=x[0];if(!y.empty())b.S=y[0];return a<b;});
    for (auto i:combs)
        print(i);
    cout<<combs.size();
    return 0;
}






