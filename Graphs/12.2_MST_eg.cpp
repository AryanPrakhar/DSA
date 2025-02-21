// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// Q. Shichikuji And Power Grid Codeforces #597 Div2D
// 1 to N cities
// building powerstation has ci cost
// connecting cities has cost ki+kj per km. Distance between cities by cartersian rule. 

// i/p, n cities, each xi yi coordinates. c1,c2,...cn powerstation build cost. k1,k2,....kn
// o/p, number of powerstation built, their coordinates, number of cities connected, their coordinates


// solution psyche
// think inteconnecting all, MST stuff
// c1,c2,c3...c4 should act like edges
// create a zero node, and connect each city with wt c1,c2,c3,c4.   DONE! Absolute Cinema!!!!!

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
    int n; cin>>n; // nodes and edges
    vector<pair<int,int>> cities(n+1);
    for(int i=1;i<=n;i++){
        cin>>cities[i].first>>cities[i].second;
    }
    vector<int> c(n+1),k(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) cin>>k[i];

    vector<pair<ll,pair<int,int>>> edges;
    
    for(int i=1;i<=n;i++){
        edges.push_back({c[i],{0,i}});
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
            ll cost=dist*1LL*(k[i]+k[j]);
            edges.push_back({cost,{i,j}});
        }
    }


    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    vector<int> power_stations;
    vector<pair<int,int>> connections;

    ll total_cost=0;
    for(auto& edge: edges){
        int wt=edge.first;
        int u,v;
        u=edge.second.first;
        v=edge.second.second;

        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        if(u==0 || v==0){
            power_stations.push_back(max(u,v));
        }
        else{
            connections.push_back({u,v});
        }
    }
    cout<<total_cost<<endl;
    cout<<power_stations.size()<<endl;
    for(int station: power_stations) cout<<station<<" ";
    cout<<endl;
    cout<<connections.size()<<endl;
    for(auto &conn: connections) cout<<conn.first<<" "<<conn.second<<" \n";

}

int main() {
    solve();
    return 0;
}