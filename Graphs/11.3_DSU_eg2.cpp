// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

int parent[N];
int siz[N]; // to store size of each group
multiset<int> sizes;

void make(int v){
    parent[v]=v;
    siz[v]=1;
    sizes.insert(1);
}

int find(int v){
    if(v==parent[v]) return v; 
    //path compression
    return parent[v]=find(parent[v]); 
}

// union by size/rank
void Union(int a,int b){
    
    a=find(a);
    b=find(b);
    if(a!=b){
        if(siz[a]<siz[b]) swap(a,b); // hamesha a bada, b chhota
        parent[b]=a;
        merge(a,b);
        siz[a]+=siz[b];
    }
}

void merge(int a,int b){
    //sizes.erase(siz[a]);  // 5 ones honge to panchon ud jaynenge, rather use iterator
    sizes.erase(sizes.find(siz[a]));
    sizes.erase(sizes.find(siz[b]));
    sizes.insert(siz[a],siz[b]);
}

void solve() {
    int n,q;
    cin>>n>>q;
    int ct;

    for(int i=1;i<=n;i++) make(i);

    while(q--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
        if(sizes.size()==1) cout<<0<<endl;
        else{
            int mn=*(sizes.begin());
            int mx=*(--sizes.end());
            cout<<mx-mn<<endl;
        }
    }
    for(int i=1;i<=n;i++){
        if(find(i)==i) ct++;
    }
    cout<<ct<<endl;
}

// Refreshing Data Structure after the Floyd Warshall onslaught :)

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}