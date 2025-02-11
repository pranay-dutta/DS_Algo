// Approach 1:
// TC: O(n * m)
// SC: O(1)
class Solution {
 public:
  string removeOccurrences(string s, string part) {
    int n = s.size(), m = part.size();
    for (int i = 0; i < n;) {
      int k = i, j = 0;

      while (s[k] == part[j] && j < m) {
        k++, j++;
      }

      if (j == m) {
        s.erase(i, m);  // i se m number of characters
        i = 0;
        n = s.size();
      } else {
        i++;
      }
    }
    return s;
  }
};
  