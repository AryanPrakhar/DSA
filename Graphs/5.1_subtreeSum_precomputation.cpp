// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;

int subtree_sum[N];   // subtree of i is sum of i's subtree

vector<int> g[N];

typedef long long ll;
typedef vector<ll> vll;



void dfs(int vertex,int parent){

    subtree_sum[vertex]+=vertex;

    for(int child: g[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];   
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

    int q;
    while(q--){
        int v;
        cin>>v;
        cout<<subtree_sum[v];
    }
    
    return 0;
} 