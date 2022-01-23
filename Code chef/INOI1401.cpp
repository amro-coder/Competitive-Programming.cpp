//problem Statement:
//In a grid of size R x C, you need to find the number of paths from the top-left to the bottom-right.
//You may only move 1 block to the right or one block down in each step.
//You may not go through any blocked intersections (given), and you may take at most d consecutive steps in the same direction. R, C <= 300.
//
//solution:
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
        for(int j=c-1;j>=0;j--) {
            if (grid[i][j] == 0 || ((i == r - 1) && (j == c - 1)))
                continue;
            for (int moves_left = 1; moves_left <= d; moves_left++) {
                //          if we go right
                dp[i][j][moves_left][0] =
                        (dp[i][j + 1][moves_left - 1][0] % 20011 + dp[i][j + 1][d][1] % 20011) % 20011;
                //          if we go down
                dp[i][j][moves_left][1] =
                        (dp[i + 1][j][moves_left - 1][1] % 20011 + dp[i + 1][j][d][0] % 20011) % 20011;
            }
        }
    cout<<(dp[0][0][d][0]+dp[0][0][d][1])%20011<<'\n';

    return 0;
}





