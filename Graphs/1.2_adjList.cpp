// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main(){

    ll n,edges;
    cin>>n>>edges;

    //array of vectors
    vll adjList[n];

    //adjacency list
    for(ll i=0;i<edges;i++){
        ll u,v;
        cin>>u>>v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    //SC: O(V+E)


    return 0;
} 