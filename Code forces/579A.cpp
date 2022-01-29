//You are a lover of bacteria. You want to raise some bacteria in a box.
//
//Initially, the box is empty.
// Each morning, you can put any number of bacteria into the box.
// And each night, every bacterium in the box will split into two bacteria.
//You hope to see exactly x bacteria in the box at some moment.
//
//What is the minimum number of bacteria you need to put into the box across those days?

//solution:
#include <bits/stdc++.h>
using namespace std;
int main() {int n;cin>>n;bitset<40> s(n);cout<<s.count();return 0;}