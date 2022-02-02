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
int n;
vi value;

vi possiple_sums(){
    int max_value= accumulate(value.begin(),value.end(),1);
    vb dp(max_value);
    dp[0]=true;
    for (int i=0;i<n;i++)
        for(int j=max_value;j>=value[i];j--)
            dp[j] = dp[j-value[i]] | dp[j];
    vi ans;
    for(int i=0;i<=max_value;i++)
        if(dp[i])
            ans.PB(i);
    return ans;
}

vi number_of_occurrences(){
    int max_value= accumulate(value.begin(),value.end(),1);
    vi dp(max_value);
    dp[0]=1;
    for (int i=0;i<n;i++)
        for(int j=max_value;j>=value[i];j--)
            dp[j] += dp[j-value[i]];
    return dp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    value.resize(n);
    for(auto &i:value)cin>>i;
    print(possiple_sums());
    print(number_of_occurrences());

    return 0;
}





