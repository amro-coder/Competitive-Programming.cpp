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
    cout<<'\n';
}

pair<vi,int> merge_with_inversions(vi x,vi y){
    vi sorted;
    int inversions=0;
    auto elex=x.begin();
    auto eley=y.begin();
    while (true) {
        if(elex==x.end()){
            sorted.insert(sorted.end(),eley,y.end());
            break;
        }
        if(eley==y.end()){
            sorted.insert(sorted.end(),elex,x.end());
            inversions+=(y.size()*(x.end()-elex));
            break;
        }
        if (*elex > *eley) {
            sorted.insert(sorted.end(), *eley);
            eley++;
        }
        else{
            sorted.insert(sorted.end(), *elex);
            elex++;
            inversions+=(eley-y.begin());
        }

    }
    return MP(sorted,inversions);
}

pair<vi,int> merge_sort_with_inversions(int n,vi x){
    if(n==1){
        return MP(x,0);
    }
    vi y(n-(n/2));
    copy(x.begin()+(n/2),x.end(),y.begin());
    x.resize(n/2);
    auto tempx= merge_sort_with_inversions(n/2,x);
    auto tempy= merge_sort_with_inversions(n-(n/2),y);
    auto temp=merge_with_inversions(tempx.F,tempy.F);
    return MP(temp.F,tempx.S+tempy.S+temp.S);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x(n);
    for(auto &i:x)cin>>i;
    auto temp= merge_sort_with_inversions(n,x);
    print(temp.F);
    cout<<temp.S;
    return 0;
}