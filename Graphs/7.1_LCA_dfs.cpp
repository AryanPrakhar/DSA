// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;

vector<int> g[N];
int par[N];

void dfs(int vertex, int parent=-1){
    par[vertex]=parent;
    for(int child: g[vertex]){
        if(child==parent) continue;
        dfs(child,vertex);
    }
}

// Function to reconstruct the path from a given node to the root (node 1)
vector<int> path(int v) {
    vector<int> ans; // Vector to store the path
    while (v != -1) {  // Changed condition to v != -1 to handle the case where the root's parent is -1.
        ans.push_back(v); // Add the current node to the path
        v = par[v];      // Move to the parent of the current node
    }
    reverse(ans.begin(), ans.end()); // Reverse the path to get it from the node up to the root
    return ans; // Return the constructed path
}

void solve() {
    int n;
    cin >> n; // Read the number of nodes in the tree

    // Read the edges and build the adjacency list
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y; // Read an edge between nodes x and y
        g[x].push_back(y); // Add y to the adjacency list of x
        g[y].push_back(x); // Add x to the adjacency list of y (tree is undirected)
    }

    int x, y;
    cin >> x >> y; // Read the two nodes for which we need to find the LCA

    dfs(1); // Perform DFS starting from node 1 (assuming it's the root) to precompute parents

    vector<int> path_x = path(x); // Get the path from node x to the root
    vector<int> path_y = path(y); // Get the path from node y to the root

    int min_len = min(path_x.size(), path_y.size()); // Find the minimum length of the two paths

    int lca = -1; // Initialize the LCA to -1 (invalid node)

    // Iterate through the paths to find the LCA
    for (int i = 0; i < min_len; i++) {
        if (path_x[i] == path_y[i]) { // If the nodes at the current level are the same
            lca = path_x[i];       // Update the LCA
        } else {
            break; // If the nodes are different, we've found the LCA (the last common node)
        }
    }

    cout << lca << endl; // Print the LCA
}

int main() {
solve();
    return 0;
}



// Time complexity: O(N)
