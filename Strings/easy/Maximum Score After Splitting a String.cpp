// Approach 1:
// TC: O(2n-2) = O(n)
// SC: O(1)
class Solution {
 public:
  int maxScore(string s) {
    int n = s.length();

    int zero = 0;
    int one = 0;

    for (int i = 1; i < n; i++) {
      one += s[i] == '1' ? 1 : 0;
    }

    int ans = zero + one;
    for (int i = 0; i < n; i++) {
      if (i != n - 1 && s[i] == '0') zero++;
      else if (i != 0) one--;
      ans = max(ans, one + zero);
    }
    return ans;
  }
};

// Approach 2:
// TC: O(1) SC: O(2n)
class Solution {
 public:
  int n;
  int l[500];
  int r[500];

  int goRight(int i, string &s) {
    if (i >= n) return 0;
    if (r[i] != -1) return r[i];  // memoize
    return r[i] = goRight(i + 1, s) + (s[i] == '1' ? 1 : 0);
  }

  int goLeft(int i, string &s) {
    if (i < 0) return 0;
    if (l[i] != -1) return l[i];  // memoize
    return l[i] = goLeft(i - 1, s) + (s[i] == '0' ? 1 : 0);
  }

  int maxScore(string s) {
    memset(l, -1, sizeof(l));
    memset(r, -1, sizeof(r));
    n = s.length();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int zero = goLeft(i, s);
      int one = goRight(i + 1, s);
      ans = max(ans, zero + one);
    }
    return ans;
  }
};
