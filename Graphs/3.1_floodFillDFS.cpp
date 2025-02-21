// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void dfs(ll i,ll j, ll initialColor, ll newColor,vector<vector<int>>& image){

    ll n=image.size();
    ll m=image[0].size();

    if(i<0 || j<0) return;
    if(i>=n || j>=m) return;
    if(image[i][j]!=initialColor) return;

    image[i][j]=newColor;

    dfs(i-1,j,initialColor, newColor,image);
    dfs(i+1,j,initialColor, newColor,image);
    dfs(i,j-1,initialColor, newColor,image);
    dfs(i,j+1,initialColor, newColor,image);
}


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        ll initialColor=image[sr][sc];
        if(initialColor!=newColor) dfs(sr,sc,initialColor,newColor,image);
}

int main(){

    return 0;
} 