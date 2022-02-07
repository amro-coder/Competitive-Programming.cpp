//using segment tree for updating a range of values
//        the idea is we build a difference array such that array[i]=sum(diff_array[0] to diff_array[i])
//then when we update a range all we have to do is increase (new_element - old_element) to the index of start of the range
//and decrease the element after the range by (new_element - old_element)
//explanation:
//changing a range of values will not change the diferences inside the range but will only change the differences in the first
//        element and last element of the range
//        so all we have to do is make a segment tree for the difference array
//        and to get an element in index i all we have to do is get the sum from the beginning to i
//using the segment tree each operation will take O(log n)

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
void update_range_segment_tree(int a,int b,int value){
    // increase the range by value
    a+=n;
    while (a>0){
        segment_tree[a]+=value;
        a>>=1;
    }
    // update the element after the range
    b+=n+1;
    while (b>0){
        segment_tree[b]+=value;
        b>>=1;
    }
    return;

}
int get_index_value(int index){
//  a,b are included
    int a=0;
    a+=n;index+=n;
    int ans=0;
    while (a<=index){
        if(a&1) ans+= segment_tree[a++];
        if(!(index&1)) ans+= segment_tree[index--];
        a>>=1;index>>=1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>old_n;
    old_n++;
    n= pow(2,ceil(log2(old_n)));
    x.resize(n);
    fill(x.begin(), x.end(),0 );
    for (int i=0;i<old_n-1;i++)cin>>x[i];
    vi diff_x(n);
    diff_x[0]=x[0];
    for(int i=1;i<n;i++)diff_x[i]=x[i]-x[i-1];

    construct_segment_tree(diff_x);
    print(segment_tree);
    cout<<get_index_value(3)<<'\n';
    update_range_segment_tree(0,4,10);
    print(segment_tree);
    cout<<get_index_value(3)<<'\n';
    return 0;
}





