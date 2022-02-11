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
void DFS(int node){
    vi stack={node};
    while (!stack.empty()){
        int parent=stack.back();
        stack.pop_back();
        if(!visited[parent]){
// main difference here the parent is the one becoming true not children, because we visit nodes in the order of parents taken.
            visited[parent]=true;
            cout<<parent<<' ';
            for (auto child:graph[parent])
                if(!visited[child])
                    stack.PB(child);
        }
    }
    cout<<'\n';
    return;
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
    DFS(start);
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