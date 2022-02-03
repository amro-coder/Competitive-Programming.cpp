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
    int n;cin>>n;
    vi x(n);
    for (auto &i:x)cin>>i;
    stack<int> s;
    map<int,int> ans;
    int i=0;
    while (i<n){
        if(s.empty()){
            s.push(x[i]);
            i++;
        } else
        if(s.top()<x[i]){
            ans[s.top()]=x[i];
            s.pop();
        } else{
            s.push(x[i]);
            i++;
        }
    }
    for(auto i:ans)
        cout<<i.F<<' '<<i.S<<'\n';

    return 0;
}





