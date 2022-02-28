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

const ll INF=(1LL<<60);
int n,m;
vector<vl> graph;
vector<vl> distances;

// the idea is each path consisit of a node as an intermediate node so if we try each node in the graph as an intermidiate node
// and then traverse the whole graph using this node as an intermediate node then ofcourse we can get all shortest pathes between
// any two nodes!!
// assume we have a negative cycle between nodes a,b,c. Then when we use a node connected to a negative edge as an intermediate node
// (let's assume this node is a) then defintely we reached b or c with a negative weight ( let's assume it's b) then when we finally
// use b as an itermediate node and as an end node the distance to reach b from b will be negative !!!
// so we can easily detect a negative cycle.

bool floyd_warshal(){
    for (int intermediate_node=0;intermediate_node<n;intermediate_node++)
        for (int start=0;start<n;start++)
            for (int end=0;end<n;end++)
                distances[start][end]=min(distances[start][end],distances[start][intermediate_node]+distances[intermediate_node][end]);
// checking for a negative cycle
    for (int i=0;i<n;i++)
        if(distances[i][i]<0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
//  using adjeceny matrix
    graph.resize(n,vl(n,INF));
    for(int i=0;i<m;i++){
        ll a,b,w; cin>>a>>b>>w;
        graph[a][b]=w;
//      to make edges bidirectional
        graph[b][a]=w;
    }

    distances.resize(n,vl(n,INF));
    for (int i =0;i<n;i++)
        for (int j=0;j<n;j++) {
            distances[i][j] = graph[i][j];
            if(i==j)
                distances[i][j]=0;
        }

    if(floyd_warshal()){
        print2D(distances);
    } else
        cout<<"a negative cycle exist\n";

    return 0;

}

//example input:
//5 6
//0 1 5
//0 2 1
//2 3 1
//1 3 2
//1 4 3
//3 4 10

//example input with a negative cycle
//5 7
//0 1 5
//0 2 1
//2 3 1
//1 3 2
//1 4 3
//3 4 10
//4 0 -9


