// Approach 1:
// TC: O(m)
// SC: O(1)
class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int m = flowerbed.size();
    for (int i = 0; i < m && n > 0; i++) {  // O(m)
      if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0)  // i==0 i-1 will not be checked
          && (i == m - 1 || flowerbed[i + 1] == 0)) {

        flowerbed[i] = 1;
        n--;
        i++;  // Skip the next spot since adjacent planting is not allowed
      }
    }
    return n == 0;
  }
};
