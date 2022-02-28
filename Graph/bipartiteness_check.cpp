#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef unordered_set<int> usi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<pi> vp;



#define F first
#define S second
#define PB push_back
#define MP make_pair

void print(usi x){
    for(auto i:x)
        cout<<i<<' ';
    cout<<'\n';
}

vector<vi> graph;
int n,m;
vb visited;
usi blacks;
usi whites;
void BFS_colouring(int node){
    queue<int> q;
    q.push(node);
    visited[node]=true;
    blacks.insert(node);
    while (!q.empty()){
        int parent=q.front();q.pop();
        for (auto child:graph[parent]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
                if(blacks.count(parent))
                    whites.insert(child);
                else
                    blacks.insert(child);
            }
        }

    }
    return;
}

tuple<bool,usi,usi> is_bipartite(){
    visited.resize(n+1);
    for(int i=0;i<n;i++)
        if(!visited[i])
            BFS_colouring(i);
    tuple<bool,usi,usi> not_bipartite={false,{},{}};
    for (auto parent:blacks)
        for (auto child:graph[parent])
            if(blacks.count(child))
                return not_bipartite;

    for (auto parent:whites)
        for (auto child:graph[parent])
            if(whites.count(child))
                return not_bipartite;

    tuple<bool,usi,usi> bipartite={true,blacks,whites};
    return bipartite;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;// n starts from zero
    graph.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
    auto ans=is_bipartite();
    auto bipartite=get<0>(ans);
    auto black=get<1>(ans);
    auto white=get<2>(ans);
    if(bipartite) {
        cout << "graph can be divided into blacks: ";
        print(blacks);
        cout << "and whites:  ";
        print(whites);
    } else cout << "graph is not bipartite";
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


