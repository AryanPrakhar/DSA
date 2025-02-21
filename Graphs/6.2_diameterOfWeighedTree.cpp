// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector<pair<int, int>> g[N];  // Adjacency list with weights
ll depth[N];  // Stores weighted depth

void dfs(int vertex, int parent = -1) {
    for (auto [child, weight] : g[vertex]) {
        if (child == parent) continue;
        depth[child] = depth[vertex] + weight;
        dfs(child, vertex);
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }

    memset(depth, 0, sizeof(depth));  
    dfs(1);  // Run DFS from any random node

    int max_d_node = 1;
    ll mx_depth = -1;

    for (int i = 1; i <= n; ++i) {
        if (mx_depth < depth[i]) {
            mx_depth = depth[i];
            max_d_node = i;
        }
    }

    memset(depth, 0, sizeof(depth));  
    dfs(max_d_node);  // DFS from max depth node

    mx_depth = -1;
    for (int i = 1; i <= n; i++) {
        if (mx_depth < depth[i]) {
            mx_depth = depth[i];
        }
    }

    cout << mx_depth << endl;
}

int main() {
    solve();
    return 0;
}
