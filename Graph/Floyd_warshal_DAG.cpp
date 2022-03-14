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
    int n,m;cin>>n>>m;
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
    vector<vl> dp(n,vl(n,INF));
    for (int node=0;node<n;node++)
        dp[node][node]=0;
    // dp[i][j] represents the shortest path from node i to node j.
    for (int i=n-1;i>=0;i--)
        for (auto child : graph[topo_sort[i]])
            for (int j=i+1;j<n;j++)
                dp[topo_sort[i]][topo_sort[j]]=min(dp[topo_sort[i]][topo_sort[j]],child.F+dp[child.S][topo_sort[j]]);
    print2D(dp);
}


//6 7
//0 2 4
//0 1 3
//1 3 1
//3 2 2
//2 4 7
//3 5 1
//5 4 2


//6 7
//0 1
//1 2
//1 3
//3 2
//0 4
//4 5
//5 0