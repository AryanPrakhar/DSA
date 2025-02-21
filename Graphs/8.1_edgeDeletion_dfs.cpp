// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int M=1e9+7;

vector<int> g[N];

int subtree_sum[N];

void dfs(int vertex, int parent=-1){
    subtree_sum[vertex]+=vertex;
    for(int child: g[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
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

    dfs(1);
    ll ans=-1;
    for(int i=2;i<=n;i++){
        int part1=subtree_sum[i];
        int part2=subtree_sum[1]-part1;
        ans=max(part1*1LL*part2,ans)%M;
    }

    cout<<ans<<endl;


}

int main() {
solve();
    return 0;
}