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
// notice that the BFS visits the nodes in increasing order of their distances from the beginning node
// meaning that each node is going to be visited by the best distance only.

//graph with no weights
vector<vi> graph;
int n,m;
vb visited;
vi BFS(int node){
    vi distances(n+1,-1);
    queue<int> q;
    q.push(node);
    visited[node]=true;
    distances[node]=0;
    while (!q.empty()){
        int parent=q.front();q.pop();// already visited
        for (auto child:graph[parent]){
            if(!visited[child]){
//notice we make the child visited unlike DFS because we visit the children of each current node.
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
    int start;
    cin>>n>>m>>start;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    visited.resize(n+1);
    print(BFS(start));
    return 0;
}

//example for input:
//10 10 0
//0 1
//0 3
//0 2
//1 4
//3 5
//5 7
//3 6
//2 8
//8 9
//9 10