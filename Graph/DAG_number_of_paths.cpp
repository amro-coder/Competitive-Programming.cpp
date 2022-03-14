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
void print(vi x) {
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
vi visited;
vi topo_sort;
bool dfs(int node){
    if (visited[node]==1)
        return true;
    visited[node]=1;// node is under processing
    bool cycle= false;
    for (auto child:graph[node])
        if (visited[child]!=2)
            cycle|=dfs(child);
    visited[node]=2;
    topo_sort.PB(node);
    return cycle;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,start;cin>>n>>m>>start;
    n++;// if nodes starts from 1
    graph.resize(n);
    for (int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
    }
    visited.resize(n);
    bool cycle;
    for (int node=0;node<n;node++)
        if (visited[node]==0)
            cycle|=dfs(node);
    reverse(topo_sort.begin(),topo_sort.end());
//  we want the number of paths from the start to all the other nodes
//  notice using topological sorting allows us to us dp easily
    vi dp(n);
    dp[start]=1;// dp[i] represents number of ways to reach i from start
    for (auto node:topo_sort)
        for (auto child : graph[node])
            dp[child]+=dp[node];// each node is going to be processed after all nodes that can reach he are porcessed
    print(dp);

}


//6 7 1
//1 2
//1 4
//4 5
//5 2
//5 3
//2 3
//3 6