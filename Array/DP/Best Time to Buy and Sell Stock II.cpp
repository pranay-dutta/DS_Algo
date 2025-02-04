// Approach 1: optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    int n = prices.size();

    // sell & buy if the buy was low [increases the of profit]
    for (int i = 1; i < n; i++) {
      if (prices[i - 1] < prices[i]) {
        profit += (prices[i] - prices[i - 1]);
      }
    }
    return profit;
  }
};