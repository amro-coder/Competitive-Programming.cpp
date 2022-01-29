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

int ans=0,n;
vector<vb> visited;
void number_of_ways(int i,int j,int num){
    if(i<0 || j<0 || i>=n || j>=n)
        return;
    if(!visited[i][j]){
        num++;
        visited[i][j]=true;
        if(i==n-1 and j==n-1){
            if(num== pow(n,2))
                ans++;
            visited[i][j]=false;
            num--;
            return;
        }

        if((i-1<0 || visited[i-1][j])and(i+1>=n || visited[i+1][j])){
            if(j-1>=0 and j+1<=n-1 and !visited[i][j-1] and !visited[i][j+1]){
                visited[i][j]=false;
                num--;
                return;
            }

        }

        if((j-1<0 || visited[i][j-1])and(j+1>=n || visited[i][j+1])){
            if(i-1>=0 and i+1<=n-1 and !visited[i-1][j] and !visited[i+1][j]){
                visited[i][j]=false;
                num--;
                return;
            }
        }




        number_of_ways(i,j+1,num);
        number_of_ways(i,j-1,num);
        number_of_ways(i+1,j,num);
        number_of_ways(i-1,j,num);
        visited[i][j]=false;
        num--;
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vb temp;
    for (int i=0;i<n;i++)
        temp.PB(false);
    for(int i=0;i<n;i++)
        visited.PB(temp);
    visited[0][0]=true;
    number_of_ways(0,1,1);
    cout<<2*ans;
    return 0;
}





