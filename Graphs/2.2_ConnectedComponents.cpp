#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

typedef long long ll;
typedef vector<ll> vll;

vll g[N];
vector<vector<ll>> cc;
vector<ll> current_cc;


bool vis[N];

//Explaination
//number of connected components - jitni baar DFS chala
//unvisited vertex pe DFS chalana hai

void dfs(ll vertex){ 
    current_cc.push_back(vertex);  

    vis[vertex]=true;
    
    for(ll child: g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
} 

int main(){
    ll n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        ll v1,v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    ll cnt=0;

    for(ll i=1;i<=n;i++){
        if(vis[i]) continue;
        current_cc.clear();
        dfs(i);
        cc.push_back(current_cc);

        cnt++;
    }

    cout<<cc.size()<<endl;
    for(auto c_cc: cc){
        for(ll vertex: c_cc){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }

} 

//finding number of connected components and listing them has O(V+E) time complexity