// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// imagine lots of people
// make sets, connect sets
// how many sets, no of properties of certain kind.
// group related questions me very useful

// it is a data structure
// 3 fxns
// make fxn - adds new independent node in the network
// find fxn - returns parent/root node of the group eg. 1->2 find(1)=1, find(2)=1
// union fxn - puts element a and b in same group - now whole set of a and b are single group. connection is made in the root nodes

int parent[N];
int siz[N]; // to store size of each group

void make(int v){
    parent[v]=v;
    siz[v]=1;
}

int find(int v){
    if(v==parent[v]) return v; // jab tak node is not the parent itself, recursion continues
    //path compression
    return parent[v]=find(parent[v]); //parent milta jayega but assign bhi hota jayega
}

// 2 basis of merging
// size - size of tree
// rank- depth of tree
// both have same TC

void Union_simple(int a,int b){
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}

// union by size/rank
// bade tree me chhota tree jodna hai
void Union(int a,int b){
    
    a=find(a);
    b=find(b);
    if(a!=b){
        if(siz[a]<siz[b]) swap(a,b); // hamesha a bada, b chhota
        parent[b]=a;
        siz[a]+=siz[b];
    }
}

// path compression - if there is a large tree, every find() gives a single node. So, just equalize the tree for improved TC.
// find operation for first time call karte karte path compression karte jayenge

// Time Complexity: O(alpha(n)) where alpha(n) is reverse Ackerman function (very slowly increases)
// This TC is amoterzied TC, that means, initial call me take some excess time, but for n times, average time is O(alpha(n)).
// for large n too - like n< 10^600, it's just 4 (yes 4!) ------ almost constant time

// FIND NUMBER OF CONNECTED COMPONENTS

void solve() {
    int n,k; // n nodes, k connections
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        make(i);
    }

    while(k--){
        int x,y;
        cin>>x>>y;
        Union(x,y);
    }

    int connected_ct=0;

    for(int i=1;i<=n;i++){
        if(find(i)==i) connected_ct++;
    }

    cout<<connected_ct<<endl;
}

// Refreshing Data Structure after the Floyd Warshall onslaught :)

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}