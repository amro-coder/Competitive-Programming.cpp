#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
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
    cout<<x.F<<" "<<x.S<<" ";
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
vector<vp> graph;
vi visited;
vi topo_sort;
bool dfs(int node){
    if (visited[node]==1)
        return true;
    visited[node]=1;// node is under processing
    bool cycle= false;
    for (auto child:graph[node])
        if (visited[child.S]!=2)
            cycle|=dfs(child.S);
    visited[node]=2;
    topo_sort.PB(node);
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,start;cin>>n>>m>>start;
    graph.resize(n);
    for (int i=0;i<m;i++){
        ll a,b,w;cin>>a>>b>>w;
        graph[a].PB(MP(w,b));
    }
    visited.resize(n);
    bool cycle;
    for (int node=0;node<n;node++)
        if (visited[node]==0)
            cycle|=dfs(node);
    reverse(topo_sort.begin(),topo_sort.end());
//  we want the shortest path from the start to all the other nodes
//  notice using topological sorting allows us to us dp easily
    vl dp(n,INF);
    vi parent(n,-1);
    dp[start]=0;// dp[i] represents the shortest path from start to i
    for (auto node:topo_sort)
        for (auto child : graph[node])
            if (dp[node]+child.F<dp[child.S]){
                dp[child.S]=dp[node]+child.F;// each node is going to be processed after all nodes that can reach he are porcessed
                parent[child.S]=node;
            }
    print(dp);

//  creating a new graph that only contains edges needed for the start node to reach all the nodes with the shortest path
    vector<vp> new_graph(n);
    for (int node=0;node<n;node++)
        if (parent[node]!=-1)
            new_graph[parent[node]].PB(MP(dp[node]-dp[parent[node]],node));

    for (auto i:new_graph) {
        for (auto j: i)
            print_pair(j);
        cout<<"\n";
    }


}


//6 5
//5 0
//5 2
//2 3
//3 1
//4 0
//4 1


//6 7
//0 1
//1 2
//1 3
//3 2
//0 4
//4 5
//5 0