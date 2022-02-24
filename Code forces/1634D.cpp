//This is an interactive problem.
//
//We picked an array of whole numbers a1,a2,…,an (0≤ai≤109) and concealed exactly one zero in it!
// Your goal is to find the location of this zero, that is, to find i such that ai=0.
//
//You are allowed to make several queries to guess the answer.
// For each query, you can think up three distinct indices i,j,k, and we will tell you the value of max(ai,aj,ak)−min(ai,aj,ak).
// In other words, we will tell you the difference between the maximum and the minimum number among ai, aj and ak.
//
//You are allowed to make no more than 2⋅n−2 queries, and after that you have two tries to guess where the zero is.
// That is, you have to tell us two numbers i and j and you win if ai=0 or aj=0.
//
//Can you guess where we hid the zero?
//
//Note that the array in each test case is fixed beforehand and will not change during the game.
//In other words, the interactor is not adaptive.


//solution:
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
int ask(int i,int j,int k){
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    int ans;
    cin>>ans;
    return ans;
}

pi min_max(int a,int b,int c,int d) {
    int a1 = ask(a, b, c);
    int a2 = ask(a, b, d);
    int a3 = ask(a, c, d);
    int a4 = ask(b, c, d);
    if (a1 == a2 && a1 >= a3 && a1 >= a4)
        return MP(a, b);
    if (a1 == a3 and a1 >= a2 and a1 >= a4)
        return MP(a, c);
    if (a2 == a3 and a2 >= a1 and a2 >= a4)
        return MP(a, d);
    if (a1 == a4 and a1 >= a2 and a1 >= a3)
        return MP(b, c);
    if (a2 == a4 and a2 >= a3 and a2 >= a1)
        return MP(b, d);
    return MP(c, d);
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        auto ans=min_max(1,2,3,4);
        int dont_care=4;
        if(ans.F!=1 and ans.S!=1) {
            dont_care = 1;
        }
        else
        if (ans.F != 2 and ans.S != 2) {
            dont_care = 2;
        }
        else
            dont_care=3;
        for (int i=5;i<=n;i+=2)
            if(i+1<=n)
                ans=min_max(ans.F,ans.S,i,i+1);
            else
                ans = min_max(ans.F, ans.S, i,dont_care);
        cout<<"! "<<ans.F<<" "<<ans.S<<endl;
    }
    return 0;
}


