// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;


int main(){
    
    int n,edges;
    cin>>n;

    int adjMatrix[n][n]={0};

    cin>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;

        adjMatrix[u][v]=1;
        adjMatrix[v][u]=1;
    }




    return 0;
} 