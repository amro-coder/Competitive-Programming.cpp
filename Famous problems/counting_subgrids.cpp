//Counting subgrids
//consider the following problem: Given an n×m grid who's each square is either black (1) or white (0).
// calculate the number of subgrids who's all corners are black.
// 0<n,m<2500
#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
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
//  generating a random n*m grid
//  you can try different n and m if you want just change them but remember(0<n,m<2500)
    int n=2500,m=2500;
    vector<vi> grid(n,vi(m));
    for(int i=0;i<n;i++)
        for (int j=0;j<m;j++)grid[i][j]=rand()%2;
    //  forward approach
    cout<<"without using bitsets\n";
    auto start = high_resolution_clock::now();
    ll ans =0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++) {
            int count=0;
            for (int k = 0; k < m; k++)
                count+=(grid[i][k]&grid[j][k]);
            ans+=count*(count-1)/2;
        }
    cout<<ans<<'\n';
    auto stop = high_resolution_clock::now();
    cout << ((double)duration_cast<microseconds>(stop - start).count())/pow(10,6) << endl;
//  optimizing using bits
    cout<<"using bitsets\n";
    auto optimized_start = high_resolution_clock::now();
    vector<bitset<2500>> optimized_grid(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(grid[i][j])
                optimized_grid[i].set(j);
    ll optimized_ans=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            int optimized_count=(optimized_grid[i]&optimized_grid[j]).count();
            optimized_ans+=optimized_count*(optimized_count-1)/2;
        }
    cout<<optimized_ans<<'\n';
    auto optomozed_stop = high_resolution_clock::now();
    cout << ((double)duration_cast<microseconds>(optomozed_stop - optimized_start).count())/pow(10,6) << endl;

    return 0;
}



//609969642380

