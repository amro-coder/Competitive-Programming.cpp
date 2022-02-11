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
            visited[parent]=true;
            for (auto child:graph[parent])
                if(!visited[child])
                    stack.PB(child);
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
    int connected_components=0;
    for (int i=0;i<n;i++)
        if(!visited[i]){
            DFS(i);
            connected_components++;
        }
    cout<<"number of connected components= "<<connected_components<<'\n';
    return 0;
}
//example input:
//10 8
//0 1
//0 3
//1 4
//5 7
//3 6
//2 8
//8 9
//9 10