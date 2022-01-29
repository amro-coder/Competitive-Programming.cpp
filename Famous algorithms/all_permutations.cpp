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
    cout<<'\n';
}

vi x;
bitset<32> choosen;
vi perm;
int times=0;
void all_perm(int index){
    if(index==x.size()){
        print(perm);
        times++;
        return;
    }
    for (int i=0;i<x.size();i++)
        if(!choosen[i]){
            choosen[i]=1;
            perm.PB(x[i]);
            all_perm(index+1);
            choosen[i]=0;
            perm.pop_back();
        }

    return;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    x.resize(n);
    for(auto &i:x)cin>>i;
    all_perm(0);
    cout<<times;
//  built in way
//    do
//        print(x);
//    while (next_permutation(x.begin(),x.end()));
    return 0;
}





