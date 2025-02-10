// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  static string clearDigits(string& s) {
    int n = s.size(), j = 0;
    for (int i = 0; i < n; i++) {
      if (isdigit(s[i]) && j > 0) j--;
      else s[j++] = s[i];
    }
    s.resize(j);
    return s;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  string clearDigits(string s) {
    int n = s.size();

    string res;
    for (int i = 0; i < n; i++) {
      if (!res.empty() && isdigit(s[i])) {
        res.pop_back();
      } else {
        res.push_back(s[i]);
      }
    }
    return res;
  }
};
