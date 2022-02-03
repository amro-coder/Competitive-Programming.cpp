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
    int n,window_size;cin>>n>>window_size;
    vi x(n);
    for(auto &i:x)cin>>i;
    deque<pi> ans;

    int i=0;
    while (i<window_size-1) {
        if (!ans.empty() &&(ans.back().F > x[i]))
            ans.pop_back();
        else{
            ans.PB(MP(x[i],i));
            i++;
        }
    }

    int start=0;
    while (start+window_size<=n){
        if(!ans.empty() && (ans.front().S<start))
            ans.pop_front();
        int current_element=start+window_size-1;
        if (!ans.empty() && (ans.back().F > x[current_element]))
            ans.pop_back();
        else {
            ans.PB(MP(x[current_element], current_element));
            cout<<ans.front().F<<'\n';
            start++;
        }

    }
    return 0;
}





