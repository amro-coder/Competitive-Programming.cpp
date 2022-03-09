#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef tuple<int,int,int> tup;


#define F first
#define S second
#define PB push_back
#define MP make_pair

const ll INF=(1LL<<60);


// debuging tools
void print(vl x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print(vi x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print_pair(pi x){
    cout<<x.F<<" "<<x.S<<"\n";
}
void print2D(vector<vi> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
void print2D(vector<vl> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
// my code

vector<vi> graph;
vi tree_diameter;
pi dfs_farthest_node(int node,int parent,int dis){
    pi farthest_node={dis,node};
    for (auto child:graph[node])
        if (child!=parent)
            farthest_node=max(farthest_node, dfs_farthest_node(child,node,dis+1));
    return farthest_node;
}
bool dfs_get_path(int node,int parent,int end){
//  note it the path is reversed
    if (node==end) {
        tree_diameter.PB(node);
        return true;//node is the end
    }
    for (auto child:graph[node])
        if ((child!=parent) &&(dfs_get_path(child,node,end))) {
            tree_diameter.PB(node);
            return true;
        }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    graph.resize(n);
    for (int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    pi a=dfs_farthest_node(0,-1,0);
    pi b=dfs_farthest_node(a.S,-1,0);
    dfs_get_path(a.S,-1,b.S);
    print(tree_diameter);
    int diameter_size=tree_diameter.size();
    (diameter_size&1)? cout<<"center of the tree is "<<tree_diameter[diameter_size/2] : cout<<"the two centers of the tree are "<<tree_diameter[diameter_size/2]<<" "<<tree_diameter[diameter_size/2-1]<<'\n';
    return 0;
}


//10
//0 1
//1 2
//2 3
//2 4
//0 5
//5 6
//5 8
//6 7
//7 9

