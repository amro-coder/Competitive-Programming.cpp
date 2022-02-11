//Mahmoud and Ehab continue their adventures! As everybody in the evil land knows, Dr. Evil likes bipartite graphs, especially trees.
//
//A tree is a connected acyclic graph. A bipartite graph is a graph,
// whose vertices can be partitioned into 2 sets in such a way, that for each edge (u,v) that belongs to the graph, u and v belong to different sets.
// You can find more formal definitions of a tree and a bipartite graph in the notes section below.
//
//Dr. Evil gave Mahmoud and Ehab a tree consisting of n nodes and asked them to add edges to it in such a way, that the graph is still bipartite.
// Besides, after adding these edges the graph should be simple (doesn't contain loops or multiple edges).
// What is the maximum number of edges they can add?
//
//A loop is an edge, which connects a node with itself.
//Graph doesn't contain multiple edges when for each pair of nodes there is no more than one edge between them. A cycle and a loop aren't the same .


//solution:
#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vp;



#define F first
#define S second
#define PB push_back
#define MP make_pair

void print(vi x){
    for(auto i:x)
        cout<<i<<' ';
    cout<<'\n';
}

//graph with no weights
vector<vi> graph;
vb visited;
vi distances;
vi BFS(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    distances[node]=0;
    while (!q.empty()){
        int parent=q.front();q.pop();// already visited
        for (auto child:graph[parent]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
                distances[child]=distances[parent]+1;
            }
        }

    }
    return distances;
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;cin>>n;
    graph.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    visited.resize(n+1);
    distances.resize(n+1);
    BFS(1);
    array<ll,2> count= {0,0};
    for(int i=1;i<=n;i++)
        count[distances[i]%2]++;
    cout<<count[0]*count[1]-n+1;
    return 0;
}