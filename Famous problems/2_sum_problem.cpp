#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,target;cin>>n>>target;
    vi x(n);
    for(auto &i:x)cin>>i;
    sort(x.begin(),x.end());
    int i=0,j=n-1;
    bool ans =false;
    while (i<j){
        if(x[i]+x[j]==target){
            ans= true;
            break;}
        if(x[i]+x[j]<target)
            i++;
        else
            j--;
    }
    if(ans)
        cout<<"sum found using "<<x[i]<<" + "<<x[j]<<'\n';
    else
        cout<<"sum not found";
    return 0;
}





