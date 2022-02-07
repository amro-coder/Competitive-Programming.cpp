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
int old_n,n;
vi x,segment_tree;
void construct_segment_tree(vi x){
    segment_tree.resize((n<<1));
    for (int i=0;i<n;i++)segment_tree[i+n]=x[i];
    for (int i=n-1;i>0;i--)segment_tree[i]=segment_tree[i<<1]+segment_tree[i<<1 |1];
    return;
}
void update_segment_tree(int index,int new_value){
    index+=n;
    segment_tree[index]=new_value;
    while (index>1){
        segment_tree[index>>1]=segment_tree[index]+segment_tree[index ^ 1];// left ^ 1=right,right^1=left
        index>>=1;
    }
    return;

}
int get_range_sum(int a,int b){
//  a,b are included
    a+=n;b+=n;
    int ans=0;
    while (a<=b){
        if(a&1) ans+= segment_tree[a++];
        if(!(b&1)) ans+= segment_tree[b--];
        a>>=1;b>>=1;
    }
    return ans;
}

void construct_min_segment_tree(vi x){
    segment_tree.resize((n<<1));
    for (int i=0;i<n;i++)segment_tree[i+n]=x[i];
    for (int i=n-1;i>0;i--)segment_tree[i]=min(segment_tree[i<<1],segment_tree[i<<1 |1]);
    return;
}
void update_min_segment_tree(int index,int new_value){
    index+=n;
    segment_tree[index]=new_value;
    while (index>1){
        segment_tree[index>>1]=min(segment_tree[index],segment_tree[index ^ 1]);// left ^ 1=right,right^1=left
        index>>=1;
    }
    return;

}
int get_range_min(int a,int b){
//  a,b are included
    a+=n;b+=n;
    int ans=INT_MAX;
    while (a<=b){
        if(a&1) ans =min(ans,segment_tree[a++]);
        if(!(b&1)) ans= min(ans,segment_tree[b--]);
        a>>=1;b>>=1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>old_n;
    n= pow(2,ceil(log2(old_n)));
    x.resize(n);
    fill(x.begin(), x.end(),0 );
    for (int i=0;i<old_n;i++)cin>>x[i];
//  prefix_sum_segment_tree
    cout<<"prefix_sum_segment_tree\n";
    construct_segment_tree(x);
    print(segment_tree);
    cout<<get_range_sum(1,3)<<'\n';
    update_segment_tree(3,10);
    print(segment_tree);
    cout<<get_range_sum(1,3)<<'\n';
//  min_segment_tree
    cout<<"min_segment_tree\n";
    construct_min_segment_tree(x);
    print(segment_tree);
    cout<<get_range_min(1,3)<<'\n';
    update_min_segment_tree(1,20);
    print(segment_tree);
    cout<<get_range_min(1,3)<<'\n';

    return 0;
}





