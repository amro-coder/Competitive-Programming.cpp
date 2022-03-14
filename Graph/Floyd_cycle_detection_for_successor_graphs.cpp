#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;cin>>n;// each node must exactly have one child
    vi successor(n);
    for (int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        successor[a]=b;
    }
    int x=0;// the point where we start from to detect the cycle(dosen't matter)
    int a=successor[x];// a pointer moves one step forward
    int b=successor[successor[x]]; // b pointer moves two steps forward
    while (a!=b){
        a=successor[a];
        b=successor[successor[b]];
    }
//  let's say they meet after k moves then the cycle is divisble by k
//  now to determine the start node of the cycle, all we need to do is to start two pointers from x and previous meeting point
//  then we advance each one of them be one step till they meet, they will meet at the start point(see if you can proof it , it's pretty easy)
    b=x;
    while (a!=b){
        a=successor[a];
        b=successor[b];
    }
    int cycle_start=a;
//  now all is left is to calculate the cycle length
    a=successor[cycle_start];
    int length=1;
    while (a!=cycle_start) {
        a = successor[a];
        length++;
    }
    cout<<"cycle starts at node "<<cycle_start<<" and the length of the cycle is "<<length<<"\n";
}


//7
//0 1
//1 2
//2 5
//5 6
//6 3
//3 5
//4 5