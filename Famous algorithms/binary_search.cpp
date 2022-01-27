#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;
typedef vector<int> vi;

int binary_search(vi sorted,int target){
    int low=0;
    int high=sorted.size()-1;
    while (low<=high){
        int mid=(low+high)/2;
        if(sorted[mid]==target)
            return mid;
        if(target>sorted[mid])
            low=mid+1;
        else
            high=mid-1;
    }
//    return low;// first element bigger than target
//    return high; //last element smaller than target
    return -1;//target not found

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,target;
    cin>>n>>target;
    vi x(n);
    for (auto &i:x)cin>>i;
    cout<<binary_search(x,target);
    return 0;
}