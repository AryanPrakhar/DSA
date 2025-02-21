// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
vector<int> g[N];
int depth[N];

//to find the diameter: find height of all the vertices, take maximum height - thats the diameter; TC - O(n^2)

//optimum: take any root and find max depth node. This node would surely be a dia end. Max depth from this is surely a diameter of tree
//why? proof! (TBD)

void dfs(int vertex, int parent = -1) {
    for (int child : g[vertex]) {
        if (child == parent) continue;
        depth[child] = depth[vertex] + 1;  // Fix here
        dfs(child, vertex);
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

    memset(depth, 0, sizeof(depth));  // Reset depth array
    dfs(1); // DFS from any random vertex

    int mx_depth = -1;
    int max_d_node = -1;

    for (int i = 1; i <= n; ++i) {
        if (mx_depth < depth[i]) {
            mx_depth = depth[i];
            max_d_node = i;
        }
    }

    memset(depth, 0, sizeof(depth));  // Reset depth array for second DFS
    dfs(max_d_node); // DFS from max depth node

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
