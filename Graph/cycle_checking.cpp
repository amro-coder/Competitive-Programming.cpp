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
int n,m;
vb visited;
pi DFS(int node){
    int number_of_nodes=0,number_of_edges=0;
    vi stack={node};
    while (!stack.empty()){
        int parent=stack.back();
        stack.pop_back();
        if(!visited[parent]){
            number_of_nodes++;
            visited[parent]=true;
            for (auto child:graph[parent])
                if(!visited[child]) {
                    stack.PB(child);
                    number_of_edges++;
                }
        }
    }
    return MP(number_of_nodes,number_of_edges);
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
    // we check the number of edges and nodes in each connected component and if not edges=nodes-1 then there is a cycle
    bool ans=false;
    for (int i=0;i<n;i++)
        if(!visited[i]){
            auto connected_compenent= DFS(i);
            if(connected_compenent.S!=connected_compenent.F-1){
                ans= true;// a cycle exists
                break;
            }
        }
    if(ans)
        cout<<"graph contains at least one cycle\n";
    else
        cout<<"graph dose not contain any cycle\n";

    return 0;
}

// example input:
//10 11
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
//10 4

