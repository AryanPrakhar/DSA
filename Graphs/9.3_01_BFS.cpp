// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// edge weights 0 and 1
// queue me ek baar me keval 2 levels ki nodes exist kar sakti hain; x and x+1
// 0 edge wali node ko x level ka maan lo  q ke front me daal do
// 1 edge wali node ko x+1 level ka maan lo, as usual q ke back me daal do

// Question: how many directed edges to reverse to go from a to b in shortest way

// 0-1 bfs me visited array ki zaroorat nahi hai


vector<pair<int,int>> g[N];
vector<int> level(N,INF);
int n,m;

int bfs(){
    deque<int> q;
    q.push_back(1); //source
    level[1]=0;

    while(!q.empty()){
        int cur_v=q.front();
        q.pop_front();

        for(auto child: g[cur_v]){
            int child_v=child.first;
            int wt=child.second;
            if(level[cur_v]+wt<level[child_v]){
                level[child_v]=level[cur_v]+wt;
                if(wt==1){
                    q.push_back(child_v);
                }
                else{
                    q.push_front(child_v);
                }
            }
            
        }
    }
    return level[1]==INF?-1:level[N];
}

void solve() {
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        if(x==y) continue; // self loop ko consider karne se fayda nahi
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    

}

int main() {
    solve();
    return 0;


}

// TC: O(V+E)