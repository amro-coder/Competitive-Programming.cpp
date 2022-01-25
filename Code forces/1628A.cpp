//problem:
//Mihai has just learned about the MEX concept and since he liked it so much, he decided to use it right away.
//
//Given an array a of n non-negative integers, Mihai wants to create a new array b that is formed in the following way:
//
//While a is not empty:
//
//Choose an integer k (1≤k≤|a|).
//Append the MEX of the first k numbers of the array a to the end of array b and erase them from the array a, shifting the positions of the remaining numbers in a.
//But, since Mihai loves big arrays as much as the MEX concept, he wants the new array b to be the lexicographically maximum.
//So, Mihai asks you to tell him what the maximum array b that can be created by constructing the array optimally is.
//
//An array x is lexicographically greater than an array y
//if in the first position where x and y differ xi>yi or if |x|>|y| and y is a prefix of x (where |x| denotes the size of the array x).
//The MEX of a set of non-negative integers is the minimal non-negative integer such that it is not in the set.
//For example, MEX({1,2,3}) =0 and MEX({0,1,2,4,5}) =3.
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
    cout<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vi x(n);
        for (auto &i:x) cin>>i;
        vector<vi> count(n+1);
        for (int i=n-1;i>=0;i--)
            count[x[i]].push_back(i);
        int minimum=-1;
        int lastIndex=-1;
        bool check=false;
        vi ans;
        int key=0;
        while (true){
            if(count[key].size()>0){
                int temp=count[key].back();
                count[key].pop_back();
                if(temp>minimum){
                    check=true;
                    lastIndex=max(lastIndex,temp);
                    key+=1;
                }
            } else{
                if(!check)
                    lastIndex++;
                minimum=lastIndex;
                ans.PB(key);
                check= false;
                key=0;
                if(lastIndex==n-1)
                    break;

            }

        }
        cout<<ans.size()<<'\n';
        print(ans);

    }

    return 0;
}