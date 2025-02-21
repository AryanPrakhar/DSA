// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// Q. In undirected weighed graph,find a tree such that edges ka sum minimum ho. Aise tree of hi MST hi kahte hain.
// tree me loops exist nahi karte

// Kruskal's Algorithm
// - assume all nodes to be independent
// - arrange the edges in sorted order
// - if putting an edge in graph creates a loop, dont put that edge
// - o/w we consider that edge as an edge in MST

// basically ----- tab tak sorted order me edges daalte jao, aur lopp wali edges ko skip karte raho

// loop ka check - using DSU - kyuki same tree ke do nodes join karne pe zaroor cycle banega

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
    int n,m; cin>>n>>m; // nodes and edges
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    int total_cost=0;
    for(auto& edge: edges){
        int wt=edge.first;
        int u,v;
        u=edge.second.first;
        v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}

int main() {
    solve();
    return 0;
}