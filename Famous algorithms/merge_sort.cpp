#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define pb push_back

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
vi merge(vi x,vi y){
    vi sorted;
    auto elex=x.begin();
    auto eley=y.begin();
    while (true) {
        if(elex==x.end()){
            sorted.insert(sorted.end(),eley,y.end());
            break;
        }
        if(eley==y.end()){
            sorted.insert(sorted.end(),elex,x.end());
            break;
        }
        if (*elex > *eley) {
            sorted.insert(sorted.end(), *eley);
            eley++;
        }
        else{
            sorted.insert(sorted.end(), *elex);
            elex++;
        }

    }
    return sorted;
}
vi merge_sort(vi x){
    int n=x.size();
    if(n<=1)
        return x;
    vi y;
    for (int i=n/2;i<n;i++)
        y.pb(x[i]);
    x.resize(n/2);
    vi left= merge_sort(x);
    vi right= merge_sort(y);
    return merge(left,right);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x;
    for (int i=0,temp;i<n;i++){
        cin>>temp;
        x.pb(temp);
    }
    print(merge_sort(x));
    return 0;
}





