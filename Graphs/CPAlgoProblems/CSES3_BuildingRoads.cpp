// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

void dfs(int vertex,vector<vector<int>>& g,vector<bool>& vis){
    vis[vertex]=true;
    for(int child: g[vertex]){
        if(vis[child]) continue;
        dfs(child,g,vis);
    }
}

void solve() {
    int n,m; cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<bool> vis(N,false);

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans=0;
    vll joins;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        ans++;
        joins.push_back(i);
        dfs(i,g,vis);
    }
    if(joins.size()==1) cout<<0<<endl;
    else{cout<<joins.size()-1<<endl;
    for(int i=0;i<joins.size()-1;i++){
        cout<<joins[i]<<" "<<joins[i+1]<<endl;
    }}
}

int main() {
    solve();
    return 0;
}