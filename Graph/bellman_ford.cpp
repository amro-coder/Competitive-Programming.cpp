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

const ll INF=(1LL<<62);
int n,m;
vector<vector<pi>> graph;
vl distances;
vi parent_list;

// the idea is each path that dosnt visit a node twice have at most n-1 edges.
// so for a cycle to exist then a node must be visited again with different number of edges in the nth round
// and for a cycle to be negative then the visit in the n round will be better than the last visit

// notice in a bidirectional graph a negative edge forms a negative cycle between it's two edges
bool bellman_ford(int start){
    for (int round=0;round<n-1;round++)
    {   // we basicllay traverse the whole graph
        for (int parent=0; parent<n;parent++)
            for(auto child:graph[parent])
                if(distances[parent]+child.F<distances[child.S]){
                    distances[child.S]=distances[parent]+child.F;
                    parent_list[child.S]=parent;
                }
    }
//    checking for a negative cycle
    for (int parent=0; parent<n;parent++)
        for(auto child:graph[parent])
            if(distances[parent]+child.F<distances[child.S])
                return false;
    return true;
}

vi get_path(int node){
    vi ans;
    while (node!=-1){
        ans.PB(node);
        node=parent_list[node];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int start;
    cin>>n>>m>>start;
    graph.resize(n);
    for(int i=0;i<m;i++){
        ll a,b,w; cin>>a>>b>>w;
        graph[a].PB(MP(w,b));
//      to make edges bidirectional
        graph[b].PB(MP(w,a));
    }
    distances.resize(n,INF);
    distances[start]=0;
    parent_list.resize(n,-1);
    if(bellman_ford(start)){
        print(distances);
        print(get_path(n-1));
    } else
        cout<<"a negative cycle exist\n";

    return 0;

}

//example input:
//5 6 0
//0 1 5
//0 2 1
//2 3 1
//1 3 2
//1 4 3
//3 4 10

//example input with a negative cycle
//5 7 0
//0 1 5
//0 2 1
//2 3 1
//1 3 2
//1 4 3
//3 4 10
//4 0 -9


