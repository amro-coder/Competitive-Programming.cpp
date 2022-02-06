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

int n;
vi x,fenwick_tree;

int get_sum(int index){
//   index is included
    int ans=0;
    while (index>0){
        ans+=fenwick_tree[index];
        index-=(index)&(-index);
    }
    return ans;
}
int get_range_sum(int a,int b){
//   b is included
    return get_sum(b)- get_sum(a-1);
}
void update(int index,int value){
    while (index<=n){
        fenwick_tree[index]+=value;
        index+=(index)&(-index);
    }
}
void construct_fenwick_tree(){
    fenwick_tree.resize(n+1);
    fill(fenwick_tree.begin(), fenwick_tree.end(), 0);
    for(int i=1;i<=n;i++)update(i,x[i]);
}

int main() {
//  indexing starts from one
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    x.resize(n+1);
    for (int i=1;i<=n;i++)cin>>x[i];
    construct_fenwick_tree();
    cout<<get_range_sum(3,8)<<'\n';
    update(7,10);
    cout<<get_range_sum(3,8);
    return 0;
}





