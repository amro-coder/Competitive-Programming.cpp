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

void print(vector<int> x){
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

void add_edge_one_direction(int a,int b){
    graph[a].PB(b);
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



////graph with weights
//vector<vp> graph;
//void reset_graph_to_size(int n){
//    graph.resize(n+1);
//    for(int i=0;i<n;i++)
//        graph[i].resize(0);
//    return;
//}
//
//void add_edge_one_direction(int a,int b,int weight){
//    graph[a].PB(MP(weight,b));
//}
//void add_edge_both_directions(int a,int b,int weight){
//    graph[a].PB(MP(weight,b));
//    graph[b].PB(MP(weight,a));
//}
//vb create_visited(){
//    int n=graph.size();
//    vb visited(n);
//    return visited;
//}
//vi initalize_nodes_values(int value){
//    int n=graph.size();
//    vi nodes(n,value);
//    return nodes;
//}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}