// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

typedef long long ll;
typedef vector<ll> vll;

vector<int> g[N];
int depth[N], height[N];

// Explaination
//tree me cycles nahi hote. 
//only way to fail is wapas oopar ki or jana
//but iske liye parent paas kar sakte hain

void dfs(int vertex, int par=0){    
    for(int child: g[vertex]){  
        if(child==par) continue;
        
        depth[child]=depth[vertex]+1; //child me entry lene se pahle
        dfs(child,vertex);
        height[vertex]=max(height[vertex],height[child]+1);

    }
}

int main(){
    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1);

    return 0;
} 