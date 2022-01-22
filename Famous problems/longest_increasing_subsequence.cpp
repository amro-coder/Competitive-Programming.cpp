//Problem Statement:
//Let s = a[1] a[2] ... a[n] be an unsorted sequence of numbers.
//A subsequence of s is one in which we drop some elements and retain the rest (so we need not pick up a contiguous segment, but we preserve the order of elements).
//For instance, a[1] a[3] a[n] is a subsequence.
//Problem: Find the (length of the) longest ascending subsequence.
//note this code solves the strictly increasing version
//solution:
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define PB push_back

//if you want to see the DP
void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}

vi DP_solution(int n,vi x){
    vi dp(n,1);
    for (int i=n-2;i>=0;i--)
        for (int j = i + 1; j < n; j++) {
            if(x[j]>x[i])
                dp[i]=max(dp[i],dp[j]+1);
        }
    auto ans=max_element(dp.begin(), dp.end());
//  reconstructing solution
    int start_index=(ans-dp.begin());
    vi longest={x[(ans-dp.begin())]};
    while (true) {
        int local_max=0,local_index=-1;
        for (int i=start_index+1;i<n;i++) {
            if(x[i]>x[start_index])
                if (dp[i] > local_max) {
                    local_max = dp[i];
                    local_index = i;
                }
        }
        if(local_index==-1)
            break;
        longest.PB(x[local_index]);
        start_index=local_index;
    }
    return longest;
}

int O_nlognSolution(int n,vi x){
    vi ends={x[0]};
    for (int i=1;i<n;i++){
        auto index= lower_bound(ends.begin(),ends.end(),x[i]);
        if(index==ends.end())
            ends.push_back(x[i]);
        else
            *index=x[i];
    }
    return ends.size();

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x(n);
    for (auto &i:x)cin>>i;
    cout<<O_nlognSolution(n,x)<<'\n';
    cout<<DP_solution(n,x).size()<<'\n';
    return 0;
}





