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
bool DFS_1(int node){
    vi stack={node};
    while (!stack.empty()){
        int parent=stack.back();
        stack.pop_back();
        if(!visited[parent]){
            visited[parent]=true;
            for (auto child:graph[parent])
                if(!visited[child])
                    stack.PB(child);
        } else
            return true;

    }
    return false;
}


pi DFS_2(int node){
    int nodes=0,edges=0;
    vi stack={node};
    while (!stack.empty()){
        int parent=stack.back();
        stack.pop_back();
        if(!visited[parent]){
            nodes++;
            visited[parent]=true;
            for (auto child:graph[parent])
                if(!visited[child]) {
                    edges++;
                    stack.PB(child);
                }
        }


    }
    return MP(nodes,edges);
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
    // first way we check for each connected component if we can visit the same node twice in the same path then a cycle must exist
    cout<<"first way\n";
    visited=create_visited();
    bool ans_1=false;
    for (int i=0;i<n;i++)
        if(!visited[i]){
            ans_1|=DFS_1(i);
        }
    if(ans_1)
        cout<<"graph contains at least one cycle\n";
    else
        cout<<"graph dose not contain any cycle\n";
    // second way is to simply count number of edges in each connected component and check if its equal to the number of nodes-1 in that connected component
    cout<<"second way\n";
    visited=create_visited();
    bool ans=false;
    for(int i=0;i<n;i++)
        if(!visited[i]) {
            auto ans_2 = DFS_2(0);
            if(ans_2.F-1!=ans_2.S)//check if edges==nodes-1
            {
                ans=true;
                break;
            }
        }
    if(ans)
        cout<<"graph contains at least one cycle\n";
    else
        cout<<"graph dose not contain any cycle\n";

    return 0;
}

//10 11
//0 1
//0 3
//1 4
//3 5
//3 6
//5 7
//2 8
//8 9
//9 10
//6 2
//10 0

