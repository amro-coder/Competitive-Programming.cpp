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
    int r,c,d;
    cin>>r>>c>>d;
    vector<vi> grid(r,vector<int> (c));
    for(auto &i:grid)
        for(auto &j:i)cin>>j;
    vector<vector<vector<vi>>> dp(r+1,vector<vector<vi>>(c+1,vector<vi>(d+1,vi(2))));
//    0 = right
//    1 = down
    for(int i=0;i<=d;i++)
        dp[r - 1][c-1][i][0] = 1;
    for (int i=r-1;i>=0;i--)
        for(int j=c-1;j>=0;j--){
            if(grid[i][j]==0 || ((i==r-1)&&(j==c-1)))
                continue;
            else
//          if we go right
                for (int right_moves_left=1;right_moves_left<=d;right_moves_left++)
                    dp[i][j][right_moves_left][0]=(dp[i][j+1][right_moves_left-1][0]%20011+dp[i][j+1][d][1]%20011)%20011;
//          if we go down
            for(int down_moves_left=1;down_moves_left<=d;down_moves_left++)
                dp[i][j][down_moves_left][1]=(dp[i+1][j][down_moves_left-1][1]%20011+dp[i+1][j][d][0]%20011)%20011;
        }
    cout<<(dp[0][0][d][0]+dp[0][0][d][1])%20011<<'\n';

    return 0;
}





