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

const ll INF=(1LL<<60);


// debuging tools
void print(vl x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print(vb x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print(vi x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print(set<int> x) {
    for (auto i: x)
        cout << i << ' ';
    cout << '\n';
}
void print_pair(pi x){
    cout<<x.F<<" "<<x.S<<"\n";
}
void print2D(vector<vi> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
void print2D(vector<vl> x){
    for (auto i:x)
        print(i);
    cout<<"\n";
}
// my code
vector<vi> graph;
vector<vi> reversed_graph;
vb visited;
vi topo_sort;
set<int> SCC;
void dfs(int node){
    visited[node]=true;
    for (auto child:reversed_graph[node])
        if (!visited[child])
            dfs(child);
    topo_sort.PB(node);
}
void dfs_visit(int node){
    visited[node]=true;
    SCC.insert(node);
    for (auto child:graph[node])
        if (!visited[child])
            dfs_visit(child);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;cin>>n>>m;
    graph.resize(n);
    reversed_graph.resize(n);
    for (int i=0;i<m;i++){
        int a,b;cin>>a>>b;
//        a--;b--;// if nodes starts with one
        graph[a].PB(b);
        reversed_graph[b].PB(a);
    }
    visited.resize(n);
    for (int node=0;node<n;node++)
        if (!visited[node])
            dfs(node);
    reverse(topo_sort.begin(),topo_sort.end());
    vector<set<int>> strongly_connected_components;
    fill(visited.begin(), visited.end(), false);
    for (auto node:topo_sort)
        if (!visited[node]) {
            SCC.erase(SCC.begin(),SCC.end());
            dfs_visit(node);
            strongly_connected_components.PB(SCC);
        }
    reverse(strongly_connected_components.begin(),strongly_connected_components.end());
    for (auto i=0;i<strongly_connected_components.size();i++){
        cout<<"SCC#"<<i+1<<" :";
        print(strongly_connected_components[i]);
    }
    return 0;
}


//6 6
//5 0
//5 2
//2 3
//3 1
//4 0
//4 1


//6 7
//0 1
//1 2
//1 3
//3 2
//0 4
//4 5
//5 0


//11 18
//1 3
//3 5
//5 1
//3 11
//11 6
//11 8
//6 10
//10 8
//8 6
//5 9
//5 7
//7 9
//9 4
//4 7
//9 2
//2 4
//2 10
//9 8