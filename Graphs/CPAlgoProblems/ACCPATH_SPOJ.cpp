#include <bits/stdc++.h>
using namespace std;
 
int H, W, dp[52][52];
char grid[52][52];
int dx[] = {0, 0, 1, -1, -1, 1, -1, 1}, dy[] = {-1, 1, 0, 0, 1, 1, -1, -1};
 
int dfs(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    int mx = 1;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < H && ny < W && grid[nx][ny] == grid[x][y] + 1)
            mx = max(mx, 1 + dfs(nx, ny));
    }
    return dp[x][y] = mx;
}
 
void solve(int caseNum) {
    scanf("%d%d", &H, &W);
    if (!H && !W) return;
    
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < H; i++) scanf("%s", grid[i]);
 
    int ans = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (grid[i][j] == 'A') ans = max(ans, dfs(i, j));
 
    printf("Case %d: %d\n", caseNum, ans);
}
 
int main() {
    for (int caseNum = 1; ; caseNum++) {
        scanf("%d%d", &H, &W);
        if (!H && !W) break;
        solve(caseNum);
    }
}
