// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

ll n, m;
vector<string> g;
vector<vector<char>> steps;
pair<ll, ll> start, dest;
vector<pair<char, pair<ll, ll>>> moves = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};


bool bfs(ll x,ll y){
    queue <pair<ll,ll>> q;
    q.push({x,y});
    steps[x][y]='X';

    while(!q.empty()){
        auto[i,j]=q.front();
        q.pop();

        if(i==dest.first && j==dest.second) return true;

        for(auto [ch,mv]: moves){
            int nx=i+mv.first;
            int ny=j+mv.second;
            if(nx>=0 && ny>=0 && nx<n && ny<m && g[nx][ny]!='#' && steps[nx][ny]==0){
                q.push({nx,ny});
                steps[nx][ny]=ch;
            }
        }
    }
    return false;
}

void print_path(){
    string ans;
    for(auto [x,y]=dest;steps[x][y]!='X';){
        char ch=steps[x][y];
        ans+=ch;
        for(auto [c,mv]: moves){
            if(c==ch){
                x-=mv.first,y-=mv.second;break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n" << ans << "\n";

}

void solve() {
    cin>>n>>m;
    g.resize(n);
    steps.assign(n,vector<char>(m,0));

    for (ll i = 0; i < n; i++) {
        cin >> g[i];
        for (ll j = 0; j < m; j++) {
            if (g[i][j] == 'A') start = {i, j};
            if (g[i][j] == 'B') dest = {i, j};
        }
    }

    if(bfs(start.first,start.second)){
        cout<<"YES\n";
        print_path();
    }
    else cout<<"NO\n";

}

int main() {
    solve();
    return 0;
}