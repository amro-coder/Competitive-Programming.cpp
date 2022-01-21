#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll current_sum=0,max_sum=0;
    int n;
    cin>>n;
    vector<ll> x;
    for (int i=0,temp;i<n;i++) {
        cin >> temp;
        x.push_back(temp);
    }
    for (auto i:x){
        current_sum+=i;
        current_sum=max((ll)0,current_sum);
        max_sum=max(max_sum,current_sum);
    }
    cout<<max_sum;
    return 0;
}





