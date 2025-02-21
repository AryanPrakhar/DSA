// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// algo

int vis[8][8];
int lev[8][8];

int getX(string s){
    return s[0]-'a';
}
int getY(string s){
    return s[1]-'1';
}

vector<pair<int,int>> movements = {
    {-1, 2}, {1, 2}, {-1, -2}, {1, -2},
    {2, -1}, {2, 1}, {-2, -1}, {-2, 1}
};


bool isValid(int x,int y){
    return x>=0 && y>=0 && x<8 && y<8;
}

int bfs(string source, string dest){
    int sourceX=getX(source);
    int sourceY=getY(source);
    int destX=getX(dest);
    int destY=getY(dest);
    queue<pair<int,int>> q;
    q.push({sourceX,sourceY});
    vis[sourceX][sourceY]=1;
    lev[sourceX][sourceY]=0;


    while(!q.empty()){
        pair<int,int> v=q.front();
        int x=v.first, y=v.second;
        q.pop();
        
        for(auto movement:movements){
            int childX=movement.first+x;
            int childY=movement.second+y;
            if(!isValid(childX,childY)) continue;
            if(!vis[childX][childY]){
                q.push({childX,childY});
                lev[childX][childY]=lev[x][y]+1;
                vis[childX][childY]=1;
            }

        }
        
    }
    return lev[destX][destY];
}

void reset(){
    for(int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            lev[i][j]=0;
            vis[i][j]=0;
        }
    }
}

void solve() {
    reset();
    string a, b;
    cin>>a>>b;

    cout<<bfs(a,b)<<endl;



}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}