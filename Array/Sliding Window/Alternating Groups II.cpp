// Approach 1: Sliding window
// TC: O(n+k)
// SC: O(k-1)
class Solution {
 public:
  int numberOfAlternatingGroups(vector<int>& c, int k) {
    for (int i = 0; i < k - 1; i++) c.push_back(c[i]);

    int n = c.size(), group = 0;
    int i = 0, j = 1;

    /* Sliding window */
    while (j < n) {
      if (c[j] == c[j - 1]) i = j;
      /*
          if doesn't have alternative color & group length is < k
          so all the colors of the group can't be considerd alternative
      */

      if (j - i + 1 == k) {  // found one group
        group++;
        i++;
      }
      j++;
    }
    return group;
  }
};
