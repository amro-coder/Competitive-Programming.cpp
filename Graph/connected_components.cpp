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
vb visited;
void DFS(int node){
    vi stack={node};
    while (!stack.empty()){
        int parent=stack.back();
        stack.pop_back();
        if(!visited[parent]){
            visited[parent]=true;
            for (auto child:graph[parent]) stack.PB(child);
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    reset_graph_to_size(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        add_edge_both_directions(a,b);
    }
    int connected_components=0;
    visited=create_visited();
    for(int i=0;i<n;i++){
        if(!visited[i]){
            connected_components++;
            DFS(i);
        }
    }
    cout<<connected_components;


    return 0;
}
