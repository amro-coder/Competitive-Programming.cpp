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

vi parent;
vi size;
int find_parent(int x){
    while (x!=parent[x]) x=parent[x];
    return x;
}

bool unite(int x,int y){
    int parent_x= find_parent(x);
    int parent_y= find_parent(y);
    if (parent_x!=parent_y) {
        if (size[parent_x] < size[parent_y]) swap(parent_x, parent_y);
//      parent x has the bigger size
        size[parent_x]+=size[parent_y];
        parent[parent_y]=parent_x;
        return true;
    }
    return false;
//    return false if x and y are in the same set
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;
    size.resize(n,1);
    for (int i =0;i<n;i++) parent.PB(i);
    print(parent);
    unite(0,3);
    print(parent);
    unite(2,1);
    print(parent);
    unite(0,2);
    print(parent);
    return 0;
}





