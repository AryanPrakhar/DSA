// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e3+10;
const int INF=1e9+10;


int level[N][N];
int vis[N][N];
int val[N][N];
int n,m;

// kisi target ka shortest distance node 1 se aayega ya node 2 se aayega

// node 1 aur 2 ko queue me daal do
// normal bfs chala do

// eg question
// given a matrix, every our, every element changes to the maximum of its surrounding elements.
// After how many hours will the matrix be uniform?

// soln - take all the max elements in level 0 and run a multi-source dfs

vector<pair<int,int>> movements={
    {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}
};

bool isValid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}

int bfs(){
    
    int mx=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
           mx=max(mx,val[i][j]);
        }        
    }
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(mx==val[i][j]){
                q.push({i,j});
                level[i][j]=0;
                vis[i][j]=1;
            }
        }        
    }
    int ans=0;
    while(!q.empty()){
        auto v=q.front();
        int v_x=v.first;
        int v_y=v.second;
        q.pop();

        for(auto movement: movements){
            int childX=v_x+movement.first;
            int childY=v_y+movement.second;
            if(!isValid(childX,childY)) continue;
            if(vis[childX][childY]) continue;
            q.push({childX,childY});
            level[childX][childY]=level[v_x][v_y]+1;
            vis[childX][childY]=1; 
            ans=max(ans,level[childX][childY]);         
        }

    }
    return ans;
}

void reset(){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j]=0;
            level[i][j]=INF;
        }        
    }
    
}

void solve() {
    reset();
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>val[i][j];
        }        
    }
    cout<<bfs()<<endl;
}

int main() {
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}