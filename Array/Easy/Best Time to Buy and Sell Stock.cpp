// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buyPrice = prices[0];
    int curProfit = 0;
    int maxProfit = 0;

    for (int i = 0; i < prices.size() - 1; i++) {
      buyPrice = min(prices[i], buyPrice);
      curProfit = prices[i + 1] - buyPrice;
      maxProfit = max(curProfit, maxProfit);
    }
    return maxProfit;
  }
};
