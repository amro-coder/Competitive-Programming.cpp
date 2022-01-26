#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define pb push_back

void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
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
    vi sorted(n);
    merge(left.begin(),left .end(),right.begin(),right.end(),sorted.begin());
    return sorted;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x(n);
    for(auto &i:x)cin>>i;
    print(merge_sort(x));
    return 0;
}
