#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef tuple<int,int,int> tup;


#define F first
#define S second
#define PB push_back
#define MP make_pair

void print_pair(pi x){
    cout<<x.F<<" "<<x.S<<" ";
}
// my code
vector<tup> edges;
vector<vp> min_spaning_tree;
int total=0;
vi parent;
vi size;
int find_parent(int x){
    while (x!=parent[x]) x=parent[x];
    return x;
}

bool unite(int x,int y){
    int parent_x= find_parent(x);
    int parent_y= find_parent(y);
    if (parent_x!=parent_y) {
        if (size[parent_x] < size[parent_y]) swap(parent_x, parent_y);
//      parent x has the bigger size
        size[parent_x]+=size[parent_y];
        parent[parent_y]=parent_x;
        return true;
    }
    return false;
//    return false if x and y are in the same set
}

void kuskals_algorithm(){
    sort(edges.begin(),edges.end());
    for (auto edge:edges){
        int weight,start,end;
        tie(weight,start,end)=edge;
        if (unite(start,end)){
            total+=weight;
            min_spaning_tree[start].PB(MP(weight,end));
            min_spaning_tree[end].PB(MP(weight,start));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    n++;// if the first node is one
    for (int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        edges.PB({w,a,b});
    }
    min_spaning_tree.resize(n);
    size.resize(n);
    for (int i=0;i<n;i++)parent.PB(i);
    kuskals_algorithm();
    cout<<total<<"\n";

    for (auto i:min_spaning_tree) {
        for (auto j: i)
            print_pair(j);
        cout<<"\n";
    }

    return 0;
}






