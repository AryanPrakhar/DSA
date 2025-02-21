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

void make(int v){
    parent[v]=v;
    siz[v]=1;
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
        siz[a]+=siz[b];
    }
}

void solve() {
    int n,k;
    cin>>n>>k;
    int ct;

    for(int i=1;i<=n;i++) make(i);

    while(k--){
        int u,v;
        cin>>u>>v;
        Union(u,v);
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