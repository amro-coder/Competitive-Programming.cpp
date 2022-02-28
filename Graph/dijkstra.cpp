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
vb visited;
vl distances;
vi parent_list;

void dijkstra(int start){
    priority_queue<tup> queue;
//    (wight,node,parent)
    queue.push({0,start,-1});
    while (!queue.empty()){
        auto node=queue.top();queue.pop();
        int current_node,weight,parent_node;
        tie(weight,current_node,parent_node)=node;
        if(!visited[current_node])
        {
            visited[current_node]=true;
            distances[current_node]=-weight;
            parent_list[current_node]=parent_node;
            for (auto child:graph[current_node])
                queue.push({-child.F+weight,child.S,current_node});
        }

    }
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
        graph[b].PB(MP(w,a));
    }
    visited.resize(n);
    distances.resize(n,INF);
    parent_list.resize(n,-1);
    dijkstra(start);
    print(distances);
    print(get_path(n-1));
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





