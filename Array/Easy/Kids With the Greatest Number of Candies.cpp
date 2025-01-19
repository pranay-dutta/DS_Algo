// Approach 1:
// TC: O(n)
// SC: O(1) excluding result
class Solution {
 public:
  vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int mx = *max_element(begin(candies), end(candies));
    int n = candies.size();
    vector<bool> result(n, 0);
    for (int i = 0; i < n; i++) {
      if (candies[i] + extraCandies >= mx) result[i] = 1;
    }
    return result;
  }
};
