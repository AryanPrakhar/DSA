// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;

// algorithm
// node ko queue me dalo
// node ke har children ko queue me dalo, node ko hata do - poora level queue me
// har child ko ek ek kar ke nikalo, aur sabke children queue me dalte raho

vector<int> g[N];
int vis[N];
int level[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;

    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child: g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]=level[cur_v]+1;
            }
        }
    }
}

void solve() {
    int n; 
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;  
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
     bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<level[i]<<endl;
    }

    

}

int main() {
    solve();
    return 0;
}