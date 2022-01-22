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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x(n);
    for(auto &i:x)cin>>i;
    vi dp(n,1);
    for (int i=n-2;i>=0;i--)
        for(int j=i+1;j<n;j++)
            if(((x[j]<0 &&x[i]>0)||(x[j]>0 && x[i]<0)) && (abs(x[j])>abs(x[i])))
                dp[i]=max(dp[i],dp[j]+1);
    cout<<*max_element(dp.begin(), dp.end())<<'\n';
    return 0;
}





