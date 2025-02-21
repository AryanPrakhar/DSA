// Jai Jai SiyaRam
// कर्मण्येवाधिकारस्ते मा फलेषु कदाचन । मा कर्मफलहेतुर्भुर्मा ते संगोऽस्त्वकर्मणि ॥
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 52; // Maximum grid size
int H, W;
char grid[MAXN][MAXN];
int dp[MAXN][MAXN]; 

int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
int dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};

bool isValid(int x, int y) {
    return (x >= 0 && y >= 0 && x < H && y < W);
}

int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y]; // ✅ Use memoized value

    int max_len = 1; // Minimum path length is 1
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny) && grid[nx][ny] == grid[x][y] + 1) {
            max_len = max(max_len, 1 + dfs(nx, ny));
        }
    }
    return dp[x][y] = max_len; // ✅ Store result in dp
}

void solve(int caseNum) {
    scanf("%d%d", &H, &W);
    if (H == 0 && W == 0) return;

    memset(dp, -1, sizeof dp); // ✅ Reset dp for new test case

    for (int i = 0; i < H; i++) {
        scanf("%s", grid[i]);
    }

    int maxLength = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'A') { 
                maxLength = max(maxLength, dfs(i, j)); // ✅ Start DFS from 'A'
            }
        }
    }

    printf("Case %d: %d\n", caseNum, maxLength);
}

int main() {
    int caseNum = 1;
    while (true) {
        int H, W;
        scanf("%d%d", &H, &W);
        if (H == 0 && W == 0) break;
        solve(caseNum++);
    }
    return 0;
}
