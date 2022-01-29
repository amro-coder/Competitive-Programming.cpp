#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef long double ld;
typedef vector<int> vi;
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
vi all_sums(int n,vi x){
    vi possiple_sums;
    for (int i=0;i<(1<<n);i++){
        int sum=0;
        for (int j=0;j<n;j++)
            if(1&(i>>j))sum+=x[j];
        possiple_sums.PB(sum);
    }
    sort(possiple_sums.begin(),possiple_sums.end());
    return possiple_sums;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,target;
    cin>>n>>target;
    vi x(n/2);
    vi y(n-(n/2));
    for (auto &i:x)cin>>i;
    for (auto &i:y)cin>>i;
    x= all_sums(x.size(),x);
    y= all_sums(y.size(),y);
    print(x);
    print(y);
    int i=0,j=y.size()-1;
    while (i<x.size() and j>=0){
        if(x[i]+y[j]==target){
            cout<<"YES";
            return 0;
        }
        else if(x[i]+y[j]>target)
            j--;
        else
            i++;
    }
    cout<<"NO";
    return 0;
}






