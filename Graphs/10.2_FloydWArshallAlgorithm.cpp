// USP: All pairs shortest path
// let the graph has 6 vertices
// let k=1,2,3,4,5,6
// k=0 -> no additional vertex included in the path
// k=1 -> max 1 node allowed between source and target to get the shortest path

// if initial param=k, and path was 1,2,3,4,...k
// now for param=k+1, the shortest path from 1->k+1 remains unaltered
// if new node leads to change in shortest path - the k+1->j shortest path is- SP when k vertices were included and condition was k+1->j

// dist[i][j]=dist[i][k]+dist[k][j]; // given SP was 1,2,...k-1 already calculated

// this algo works on directed as well as undirected graphs
// this algo can hangle negative weights but not negative weighted cycles
// example
// 2->3 wt=1
// 2<-3 wt=-2
// going 2->3->2 net_dist=-1, then -2, then -3 . Shortest path keeps getting shorter

//CODE

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


int dist[N][N];

void solve(){
    rep(i,0,N){
        rep(j,0,N){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }

    int n,m; //n nodes, m edges
    cin>>n>>m;
    rep(i,0,m){
        int x,y,wt;
        cin>>x>>y>>wt;
        dist[x][y]=wt;
    }
    //main algo
    for(int k=1;k<=n;k++){  //k->level
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INF && dist[k][j]!=INF){ // condition for the case of negative weights, o/w INF vs INF-1, a min would sprawl and that's not wanted
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    // TC: O(n^3)

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;j++){
            if(dist[i][j]==INF){
                cout<<"I ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<endl;
    }

}

int main(){
    ios_fast();
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}