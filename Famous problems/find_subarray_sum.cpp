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
    for (auto &i:x)cin>>i;
    int i=0,j=0,sum=0;
    bool ans=false;
    while(true)
    {
        if(sum==target){
            ans= true;
            break;
        }
        if(i>=n | j>=n)
            break;
        if(sum<target){
            sum+=x[j];
            j++;
        } else {
            sum -= x[i];
            i++;
        }
    }
    if(ans)
        cout<<"sum found"<<" from index "<<i+1<<" to index "<<j<<'\n';
    else
        cout<<"sum not found"<<'\n';
    return 0;
}





