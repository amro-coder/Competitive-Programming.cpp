//Problem Statement:
//It's dinner time in Castle Camelot, and the fearsome Knights of the Round Table are clamouring for dessert.
//You, the chef, are in a soup. There are N knights, including King Arthur, each with a different preference for dessert, but you cannot afford to make desserts for all of them.
//You are given the cost of manufacturing each Knight's preferred dessert–since it is a round table, the list starts with the cost of King Arthur's dessert, and goes counter-clockwise.
//You decide to pick the cheapest desserts to make, such that for every pair of adjacent Knights, at least one gets his dessert.
//This will ensure that the Knights do not protest.
//What is the minimum cost of tonight's dinner, given this condition?
//For instance, suppose there are 5 Knights and their desserts cost 1, 2, 1, 2 and 2.
//In this case, the minimum cost is 4, which you can achieve by feeding the first, third and fourth (or fifth) Knights.
//
//Input format
//There are 2 lines of input.
//The first line contains a single integer N, the number of seats at the table.
//The next line contains N space separated integers, each being the cost of the dessert of a Knight, listed in counterclockwise order around the table, starting with King Arthur.
//
//Output format
//The output should be a single line containing a single integer, the minimum possible cost for you, the chef.
//
//
//Solution:
#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
// if you want to see the DP
void print(vector<int> x){
    for(auto i:x)
        cout<<i<<' ';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vi x(n);
    for (auto &i:x)
        cin>>i;
    if(n<=2){
        cout<<(*min_element(x.begin(),x.end()));
        return 0;
    }
//  including the first element
    vi dp1(n);
    dp1[n-1]=x[n-1];
    dp1[n-2]=x[n-2];
    for (int i=n-3;i>=0;i--)
        dp1[i]=min(dp1[i+1],dp1[i+2])+x[i];

    reverse(x.begin(),x.end());
//  including the last element
    vi dp2(n);
    dp2[n-1]=x[n-1];
    dp2[n-2]=x[n-2];
    for (int i=n-3;i>=0;i--)
        dp2[i]=min(dp2[i+1],dp2[i+2])+x[i];
    cout<<min(dp1[0],dp2[0]);
    return 0;
}





