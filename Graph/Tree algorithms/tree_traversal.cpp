// the main difference here is that each node in the tree can only be reached out by it's parent so we don't need a whole visited
//array instead we only need to know if this is it's parent or not.
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

vector<vi> graph;
void dfs(int node,int parent){
    cout<<node<<"\n";
    for (auto child:graph[node])
        if (child!=parent)
            dfs(child,node);
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
    dfs(0,-1);
    return 0;
}

// for bfs just do the normal bfs since the parent of each node must be saved in a list
