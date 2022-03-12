#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef vector<pi> vp;
typedef tuple<int,int,int> tup;


#define F first
#define S second
#define PB push_back
#define MP make_pair

void print_pair(pi x){
    cout<<x.F<<" "<<x.S<<" ";
}
// my code
vector<vp> graph;
vb visited;
priority_queue<tup> q;
vector<vp> min_spaning_tree;
int total=0;
void primes_algorithm(){
    q.push({0,1,-1});//pushing an aribtary node with edge cost zero and with parent -1
    while (!q.empty()){
        int node,weight,parent;
        tie(weight,node,parent)=q.top();q.pop();
        if (!visited[node]) {
            visited[node] = true;
            if (parent!=-1){
                min_spaning_tree[node].PB(MP(-weight,parent));
                min_spaning_tree[parent].PB(MP(-weight,node));
                total-=weight;
            }
            for (auto i:graph[node]){
                int child_weight=i.F;
                int child=i.S;
                q.push({-child_weight,child,node});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m; cin>>n>>m;
    n++;// if the first node is one
    graph.resize(n);
    for (int i=0;i<m;i++){
        int a,b,w;cin>>a>>b>>w;
        graph[a].PB(MP(w,b));
        graph[b].PB(MP(w,a));
    }
    visited.resize(n);
    min_spaning_tree.resize(n);
    primes_algorithm();
    cout<<total<<"\n";

    for (auto i:min_spaning_tree) {
        for (auto j: i)
            print_pair(j);
        cout<<"\n";
    }


    return 0;
}


// example input:
//6 8
//1 2 3
//1 5 5
//2 5 6
//2 3 6
//5 6 2
//3 6 3
//3 4 9
//6 4 7
