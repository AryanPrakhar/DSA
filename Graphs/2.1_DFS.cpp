// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;  //max notes

typedef long long ll;
typedef vector<ll> vll;

vll g[N];
bool vis[N];

void dfs(int vertex){

    //take action on vertex after entering the vertex
    cout<<vertex<<endl;

    vis[vertex]=true;
    
    for(int child: g[vertex]){
        if(vis[child]) continue;
        
        cout<<"par: "<<vertex<<" "<<"child: "<<child;
        //take action on child before 
        //calling dfs for the child (entering child node)
        
        dfs(child);
        //take action on child after
        //dfs operation over on child (exiting child node)
        //child se wapas aate hue
    }

    //take action on vertex before exiting the vertex
}


int main(){
    ll n,m;  //n-vertices, m-edges
    cin>>n>>m;
    for(int i=0;i<9;i++){
        ll v1,v2;
        cin>>v1>>v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
  
    return 0;
} 


// Time complexity: O(V+2*E)
