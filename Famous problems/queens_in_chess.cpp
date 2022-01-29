//how many ways to put n queens in an n*n chessboard so that they cant attack each other
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

vi col,diag1,diag2;
int n,ans=0;
void search(int row){
    if(row==n){ans++;return;}
    for (int column=0;column<n;column++)
        if((!col[column]) and (!diag1[row+column]) and (!diag2[n-1+row-column])){
            col[column]=diag1[row+column]=diag2[n-1+row-column]=1;
            search(row+1);
            col[column]=diag1[row+column]=diag2[n-1+row-column]=0;
        }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    col.resize(n);
    diag1.resize(2*n-1);
    diag2.resize(2*n-1);
    fill(col.begin(), col.end(),0);
    fill(diag1.begin(), diag1.end(),0);
    fill(diag2.begin(), diag2.end(),0);
    search(0);
    cout<<ans;
    return 0;
}





