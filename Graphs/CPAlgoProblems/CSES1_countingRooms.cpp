// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
#define ios_fast() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i, a, b) for (ll i=a; i<b; i++)
#define rrep(i, a, b) for (ll i=a; i>=b; i--)
#define yes() cout << "YES\n"
#define no() cout << "NO\n"
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
const int N = 1e5 + 10;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }

ll binpow(ll a, ll b, ll m=MOD) { ll res=1; while (b>0) {if (b&1) res=res*a%m; a=a*a%m; b>>=1;} return res;}
bool is_prime(ll n) {if (n<2) return false; for (ll i=2; i*i<=n; i++) if (n%i==0) return false; return true; }


vector<pair<int,int>> movements{
    {1,0},{-1,0},{0,1},{0,-1}
};

void dfs(int i,int j,vector<vector<char>>& A, vector<vector<bool>>& vis){
    vis[i][j]=true;
    for(auto movement: movements){
        int ni=i+movement.first;
        int nj=j+movement.second;
        if(ni>=0 && ni<A.size() && nj<A[0].size() && nj>=0 && !vis[ni][nj] && A[ni][nj]=='.'){
            dfs(ni,nj,A,vis);
        }
    }

}


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    vector<vector<bool>> vis(n,vector<bool>(m));

    rep(i,0,n){
        rep(j,0,m){
            cin>>g[i][j];
        }
    }
    int ans=0;
    rep(i,0,n){
        rep(j,0,m){
            if(g[i][j]=='.' && !vis[i][j]){
                ans++;
                dfs(i,j,g,vis);
            }

        }
    }

    cout<<ans<<endl;

}

int main(){
    ios_fast();
    solve();
    return 0;
}
