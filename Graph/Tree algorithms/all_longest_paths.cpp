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
vi all_longest_paths;
vector<vector<pi>> best_two_paths_using_child;
vi best_path_using_parent;
void dfs_best_two_paths_using_child(int node,int parent){
    vector<pi>best_two_children={MP(0,-1),MP(0,-1)};// if node has no children
    for (auto child:graph[node])
        if (child!=parent){
//          calculate the ans to my child first
            dfs_best_two_paths_using_child(child,node);
//          then use the value to compute me
            if (best_two_paths_using_child[child][1].F+1>best_two_children[0].F)
                best_two_children[0]=MP(best_two_paths_using_child[child][1].F+1,child);//best two paths using child is always sorted so the second is bigger
            sort(best_two_children.begin(),best_two_children.end());
        }
    best_two_paths_using_child[node]=best_two_children;
}

void dfs_best_path_using_parent(int node,int parent){
//  calculate my node value before going to the children
//  either use the parent of the parent or use the best child that is not the node itself
    if (parent!=-1)
        best_path_using_parent[node]= 1+max((node==best_two_paths_using_child[parent][1].S)? best_two_paths_using_child[parent][0].F:best_two_paths_using_child[parent][1].F,best_path_using_parent[parent]);
    for (auto child:graph[node])
        if (child!=parent)
            dfs_best_path_using_parent(child,node);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin>>n;
    graph.resize(n);
    for (int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        graph[a].PB(b);
        graph[b].PB(a);
    }
//  chooseing arbitary root
    int root=0;
    best_two_paths_using_child.resize(n,(vector<pi>(2)));
    best_path_using_parent.resize(n);
    all_longest_paths.resize(n);
    dfs_best_two_paths_using_child(root,-1);
    dfs_best_path_using_parent(root,-1);
    for (int node=0;node<n;node++)
//      the longest path from a node is either through it's parent or through it's children
        all_longest_paths[node]=max(best_path_using_parent[node],(*max_element(best_two_paths_using_child[node].begin(),best_two_paths_using_child[node].end())).F);
    print(all_longest_paths);

    return 0;
}


//10
//0 1
//1 2
//2 3
//2 4
//0 5
//5 6
//5 8
//6 7
//7 9

