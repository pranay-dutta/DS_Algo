// Approach 1: Optimal using memoization
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  int fib(int n) {
    if (n <= 1) return n;

    // Tabulation
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
};

// Approach 1: Recursion
// TC: O(2^n)
// SC: O(n) :stack space
class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
  }
};