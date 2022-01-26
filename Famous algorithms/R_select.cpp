#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;


#define F first
#define S second
#define PB push_back
#define MP make_pair

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
int n,pos;
vi x;
int partition(int l,int r){
//    pivot is the first element
    int i=l+1;// points to first bigger element
    for (int j=i;j<r;j++){
        if(x[j]<x[l]){
            swap(x[i],x[j]);
            i+=1;
        }
    }
    swap(x[l],x[i-1]);
    return i-1;
}

int R_select(int l,int r){
//    choose piviot
    swap(x[l],x[l+(rand()%(r-l))]);// to gurantee that the pivot is choosen randomly (even if the list is sorted(worst case))
    int p= partition(l,r);
    if(p==pos)
        return x[pos];
    else
    if(pos<p)
        return R_select(l,p);
    else
        return R_select(p+1,r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>pos;
//  pos-=1 if you want to start indexing from 1
    x.resize(n);
    for(auto &i:x)cin>>i;
    cout<<R_select(0,n)<<'\n';
    return 0;
}





