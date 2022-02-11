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

void print(vb x){
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
vb colours;
void BFS_colouring(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    while (!q.empty()){
        int parent=q.front();q.pop();
        for (auto child:graph[parent]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
                colours[child]=!colours[parent];
            }
        }

    }
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    visited.resize(n+1);
    colours.resize(n);
    for(int i=0;i<n;i++)
        if(!visited[i])
            BFS_colouring(i);
    bool ans=true;
    for(int parent=0;parent<n;parent++)
        for(auto child:graph[parent])
            ans&=colours[parent]^colours[child];
    if(ans)
        cout<<"graph is bipartite\n";
    else
        cout<<"graph is not bipartite\n";
    return 0;
}

//example for input:
//10 10
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