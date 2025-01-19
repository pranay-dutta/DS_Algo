// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int titleToNumber(string columnTitle) {
    int n = columnTitle.size();
    int colNum = 0;
    long long x = 1;
    for (int i = n - 1, j = 1; i >= 0; i--, j++) {
      colNum += (columnTitle[i] - '@') * x;
      x *= 26;
    }
    return colNum;
  }
};
