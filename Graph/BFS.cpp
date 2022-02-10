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
void reset_graph_to_size(int n){
    graph.resize(n+1);
    for(int i=0;i<n;i++)
        graph[i].resize(0);
    return;
}

void add_edge_both_directions(int a,int b){
    graph[a].PB(b);
    graph[b].PB(a);
}
vb create_visited(){
    int n=graph.size();
    vb visited(n);
    return visited;
}
vi initalize_nodes_values(int value){
    int n=graph.size();
    vi nodes(n,value);
    return nodes;
}
// notice that the BFS visits the nodes in increasing order of their distances from the beginning node
// meaning that each node is going to be visited by the best distance only
vi BFS(int node){
    vi distances= initalize_nodes_values(-1);
    vb visited=create_visited();
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
    int n,m,start;cin>>n>>m>>start;
    reset_graph_to_size(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        add_edge_both_directions(a,b);
    }
    print(BFS(start));
    return 0;
}