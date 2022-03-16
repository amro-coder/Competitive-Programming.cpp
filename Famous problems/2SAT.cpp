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
        cout << i+1 << ' ';
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
map<int,vi> graph;
map<int,vi> reversed_graph;
map<int,bool> visited;
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
    int n;cin>>n;
    set<int> all_nodes;
    for (int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        all_nodes.insert(a);
        all_nodes.insert(-a);
        all_nodes.insert(b);
        all_nodes.insert(-b);
        graph[-a].PB(b);
        graph[-b].PB(a);
        reversed_graph[b].PB(-a);
        reversed_graph[a].PB(-b);
    }
    for (auto node: all_nodes)
        if (!visited[node])
            dfs(node);
    reverse(topo_sort.begin(),topo_sort.end());
    vector<set<int>> strongly_connected_components;
    for (auto &i:visited)i.S=false;
    for (auto node:topo_sort)
        if (!visited[node]) {
            SCC.erase(SCC.begin(),SCC.end());
            dfs_visit(node);
            strongly_connected_components.PB(SCC);
        }
    bool out;
    vi ans(*max_element(all_nodes.begin(),all_nodes.end()),-1);
    for (auto i=0;i<strongly_connected_components.size();i++){
        for (auto node:strongly_connected_components[i]) {
            if (strongly_connected_components[i].count(-node)) {
                cout << "There is no way to assign values to the variables such that the equation will result Ture";
                out = true;
                break;
            }
            if (ans[abs(node)-1]==-1)
                ans[abs(node)-1]=(node>0);
        }
        if (out)
            break;
    }
    if (!out) {
        cout<<"There is a way to assign each variable a value such that the equation yields Ture, below is one way:\n";
        for (int i = 0; i < ans.size(); i++)
            cout << "The variable " << i + 1 << " should be " << (ans[i] ? "True" : "False") << "\n";
    }
    return 0;
}

//Equation 1:
//(x2 ∨ ¬x1)∧(¬x1 ∨ ¬x2)∧(x1 ∨ x3)∧(¬x2 ∨ ¬x3)∧(x1 ∨ x4)
//input form of equation 1:
//5
//2 -1
//-1 -2
//1 3
//-2 -3
//1 4
//
//Equation 2:
//(x1 ∨ x2)∧(x1 ∨ ¬x2)∧(¬x1 ∨ x3)∧(¬x1 ∨ ¬x3)
//input form of equation 2:
//4
//1 2
//1 -2
//-1 3
//-1 -3