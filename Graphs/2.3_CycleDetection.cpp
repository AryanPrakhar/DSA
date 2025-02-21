#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

typedef long long ll;
typedef vector<ll> vll;

vll g[N];
bool isLoopExists=false;

bool vis[N];

//Explaination
// jis vertex se aaya hai, uska track rakho
// iske alawa koi vertex repeat ho raha to cycle hai
// ek bhi child agar bole ki loop exist karta hai to loop exist karta hai


bool dfs(ll vertex, ll par){ 

    vis[vertex]=true;
    
    for(ll child: g[vertex]){
        if(vis[child] && child==par) continue;
        if(vis[child]) return true;

        isLoopExists|=dfs(child,vertex);
    }

    return isLoopExists;
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
        if(dfs(i,0)){  //0 by default, since kisi ka parent nahi hai
            isLoopExists=true;
            break;
        };
    }

    cout<<isLoopExists<<endl;
} 

