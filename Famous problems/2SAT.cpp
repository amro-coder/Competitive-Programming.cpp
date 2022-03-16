//we have an equation that looks like:  (a1 ∨ b1)∧(a2 ∨ b2)∧··· ∧(am ∨ bm). Where v denotes logical or and ∧ denotes logical and.
//the a1,b1.... variables are either a logical variable or a negation of a logical variable.
//we want to know if we can assign a value to each variable so that the equation is true?
//let's define an implicit graph: an implicit graph is a graph with directed edges that means if a node is true then
//all nodes it can reach are true, but if it's false then there are no constrains.
//thus we can made an implicit graph by creating two directed edges for each clause of the form (a v b)
//edge 1 :  negate a to b : meaning that if a is false (negate a is true) then b must be true
//edge 2 :  negate b to a : meaning that if b is false (negate b is true) then a must be true
//note with this edges if a is false then b is ture and vice versa.
//notice edge 1 is contrapositive to edge 2, meaning we can not use both constrains , if we use edge 1 constrains then there are no constrains form edge 2 and vice versa.
//notice if we have a path form node a to node b then it's the same as an edge from a to b, because if a is true then the whole path is true.
//so now if we have a path from a to negate a and from negate a to a then if a is false the path from a to negate a will make a contradiction
//and if a is true then the path from a to negate a will make a contradiction, hence it's impossible to assign values so the equation is correct.
//now let's define strongly connected component(SCC): a SCC is a group of nodes such that each node can reach any node in the same SCC.
//now let's rephrase, after making the implicit graph , if any two nodes x and negate x are in the same strongly connected component then
//it's impossible to assign values to such equation.
//now if it's possible how do we assign the values?
//notice that a graph with it's SCCs  as it's nodes forms an acyclic graph which we can make a topological sorting to
//        so if we start from the last SCC in the topological sorting , then we can assign the values easily
//since the component dose not leak to any other SCC, all we have to do is assign true to all nodes of the SCC
//and we keep going with this order till all variables are assigned values, notice that we don't change the value of a variable once we assign it.
//this way will guarantee that no edge is contradicted in the whole graph.
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
//    the input should be of the form :
//    n
//    1 2
//      -1 2
//    n represents the number of (a v b) clauses
//    then n lines follow with 1 meaning variable 1 and -1 meaning the negate of variable 1 and so on.
//            (a v b) ^ (¬a v b) ^ (c v ¬b)
//    input for above equation is:
//    3
//    1 2
//      -1 2
//    3 -2
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