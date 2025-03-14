// Appraoch 1:
// TC: O(2n log(m)) -- O(n log(m))
// SC: O(1)
class Solution {
 public:
  bool isDistributable(vector<int>& candies, long long kids, int eachChildGets) {
    for (int& candyPile : candies) {  // O(m)
      if (candyPile >= eachChildGets) {
        kids -= candyPile / eachChildGets;
      }
      if (kids <= 0) return true;
    }
    return false;
  }
  int maximumCandies(vector<int>& candies, long long k) {
    int maxCandies = *max_element(begin(candies), end(candies));  // O(n)
    int r = maxCandies, l = 1;
    int res = 0;

    while (l <= r) {  // O(n)
      int mid = (l + r) / 2;
      if (isDistributable(candies, k, mid)) {
        l = mid + 1;
        res = mid;
      } else {
        r = mid - 1;
      }
    }

    return res;
  }
};