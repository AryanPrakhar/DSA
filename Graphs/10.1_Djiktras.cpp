// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
const int N=2e5+10;
const int INF=1e9+10;

// we use pq to find the immediate minimum - greedy approach
// pq just allows lower time compexity - O(logN) - no need of loop
// whoever is accessed (evaluated to be next next potential node) is put in pq. As they are evaluated for greedy next- 
// each of them is deleted from the pq

// keep account of greedily counted distance

// format of an element in pq: (distance travelled, node number)

// multiset bhi same kaam kar dete hain
// yahan to set bhi use kar sakte hain cuz (3,4), (5,4), etc are still unique

vector<pair<int,int>> g[N];

void dijkstra(int source) {
    vector<int> vis(N, 0);  // Keeps track of visited nodes (Not really needed here)
    vector<int> dist(N, INF);  // Stores the shortest known distance from `source` to each node

    set<pair<int, int>> st;  
    // `set` is used to store pairs of `{distance, node}` 
    // It always keeps the smallest distance pair at the beginning (sorted order)

    st.insert({0, source});  // Start from the source with distance 0
    dist[source] = 0;  // Distance to itself is 0

    while (!st.empty()) {  // Continue until there are no nodes left to process
        auto node = *st.begin();  
        int v = node.second;  // Current node
        int v_dist = node.first;  // Distance to this node from source
        st.erase(st.begin());  // Remove the processed node
        
        if (vis[v]) continue;  // Skip if the node is already processed (but it's redundant in set-based Dijkstra)
        
        vis[v] = 1;  // Mark node as visited

        for (auto child : g[v]) {  // Iterate over all neighbors of `v`
            int child_v = child.first;  // Neighbor node
            int wt = child.second;  // Edge weight from `v` to `child_v`
            
            if (dist[v] + wt < dist[child_v]) {  // If a shorter path is found
                dist[child_v] = dist[v] + wt;  // Update shortest distance
                
                st.insert({dist[child_v], child_v});  
                // Insert the new updated distance into the set
            }
        }
    }
}



void solve() {
    int n,m; cin>>n>>m;


    for(int i=0;i<m;i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }

    

}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}