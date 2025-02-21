// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;

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

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
ll lcm(ll a, ll b) { return (a*b)/gcd(a, b); }

ll binpow(ll a, ll b, ll m=MOD) { ll res=1; while (b>0) {if (b&1) res=res*a%m; a=a*a%m; b>>=1;} return res;}
bool is_prime(ll n) {if (n<2) return false; for (ll i=2; i*i<=n; i++) if (n%i==0) return false; return true; }

// Codeforces Greg and Graphs - Div1B - Medium-Hard
// Q. Given weighted directed graph, with n vertices. There are 2 edges between any two vertices.
// game consists of n steps
// on ith step, greg removes vertex xi from graph.
// he also removes the edges that goes in and out of the vertex.
// before executing each step, greg wants to know the sum of lengths of the shortest paths between all pairs of the remaining vertices.

// how to get hint? 
// shortest path asked between all pairs.
// vertices being removed. we were adding levels - k 1->n, here we need to subtract it.

// deletion ke reverse order me floyd-warshall


ll dist[N][N];

void solve(){
    ll n;
    cin >> n;

    vll a(n); 
    vll b(n);
    for(ll i=1; i<n; i++){
        for(ll j=1;j<n;j++){
            cin>>dist[i][j];
        }
    }

    vector<int> del_order(n);
    rep(i,0,n){
        cin>>del_order[i];
    }
    reverse(del_order.begin(),del_order.end());

    for(int k=0;k<n;++k){ // since deletion order is zero based
        // level 1 is deletion order of 0
        int k_v=del_order[k];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long dist[i][j]=min(dist[i][j],dist[i][k_v]+dist[k_v][j]);
            }
        }
        ll sum=0;
        for(int i=0;i<=k;++k){
            for(int j=0;j<=k;++j){
                sum+=dist[del_order[i]][del_order[j]];
            }
        }
        ans.push_back(sum);
    }

    reverse(ans.begin(),ans.end());

    for(auto x:ans){
        cout<<x<<endl;
    }



}

int main(){
    ios_fast();
    solve();
    return 0;
}