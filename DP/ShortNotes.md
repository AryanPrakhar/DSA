### 1. 0/1 Knapsack (Classic)<br />
***Problem***: Maximize value while keeping weight under capacity <br />
***State***: dp[i][w] = max value using first i items with capacity w <br />
***Recurrence***: 
```dp[i][w] = max(dp[i-1][w], dp[i-1][w-wt[i-1]] + val[i-1])``` if item fits <br />

### 2. Subset Sum (Decision)<br />
**Problem**: Determine if a subset with given sum exists <br />
**State**: dp[i][j] = true if sum j is possible with first i elements <br />
**Recurrence**: ```dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]]``` <br />
### 3. Count of Subsets Sum (Your **Problem**)<br />
**Problem**: Count subsets with given sum<br />
**State**: dp[i][j] = number of ways to get sum j with first i elements<br />
**Recurrence**: ```dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]```<br />

### 4. Minimum Subset Sum Difference<br />
**Problem**: Partition array to minimize difference between subset sums<br />
Approach: Find all possible sums, then find minimum |S - 2*subset_sum| <br />
### 5. Target Sum (+ and - signs) <br />
**Problem**: Assign + or - to each number to achieve target sum<br />
Transformation: Count subsets with sum (target + total_sum)/2<br />
### 6. Unbounded Knapsack<br />
**Problem**: Like 0/1 knapsack but can use items multiple times<br />
**Recurrence**: ```dp[i][w] = max(dp[i-1][w], dp[i][w-wt[i-1]] + val[i-1])```<br />
Note: Using dp[i] (not dp[i-1]) when including item<br />
### 7. Coin Change (Ways)<br />
**Problem**: Count ways to make change using given coins <br />
**Recurrence**: ```
dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]]``` <br />

---

### 8. Coin Change (Minimum)

**Problem**: Minimum coins needed for change
**Recurrence**:

```cpp
// base case
for(int j = 1; j <= amount; j++) 
    t[0][j] = INT_MAX - 1;

for(int i = 0; i <= n; i++) 
    t[i][0] = 0;

for(int j = 1; j <= amount; j++) {
    if (j % coins[0] == 0) 
        t[1][j] = j / coins[0];
    else 
        t[1][j] = INT_MAX - 1;
}

// recurrence
dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
```

---



