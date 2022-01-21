#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef vector<int> vi;
#define pb push_back

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
    for (int i=0;i<n;i++){
        for (int j=0;j<n-1-i;j++){
            if(x[j]>x[j+1])
                swap(x[j],x[j+1]);
        }
    }
    for (auto i:x)
        cout<<i<<' ';
    return 0;
}