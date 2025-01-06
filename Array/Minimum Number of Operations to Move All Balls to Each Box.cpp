// Approach 4: Brute force
// TC: O(n^2)
// SC: O(1)
class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int move = 0;
      for (int j = i - 1; j >= 0; j--) {
        if (boxes[j] == '1') move += i - j;
      }
      for (int k = i + 1; k < n; k++) {
        if (boxes[k] == '1') move += k - i;
      }
      ans[i] = move;
    }
    return ans;
  }
};