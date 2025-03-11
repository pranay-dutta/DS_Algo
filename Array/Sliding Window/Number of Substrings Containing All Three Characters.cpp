// Approach 1:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  int numberOfSubstrings(string &s) {
    int n = s.size(), i = 0, res = 0;
    int mp[3] = {-1, -1, -1};

    while (i < n) {
      mp[s[i] - 'a'] = i;
      if (mp[0] != -1 && mp[1] != -1 && mp[2] != -1) {
        res += (1 + min(mp[0], min(mp[1], mp[2])));
      }
      i++;
    }
    return res;
  }
};
// Approach 2:
// TC: O(~2n) -> O(n)
// SC: O(3) -> O(1)
class Solution {
 public:
  int numberOfSubstrings(string s) {
    int n = s.length();
    int i = 0, j = 0, res = 0;

    unordered_map<char, int> mp;
    while (j < n) {
      mp[s[j]]++;

      while (i < n && mp.size() >= 3) {
        if (mp.size() >= 3) res += n - j;
        if (--mp[s[i]] == 0) mp.erase(s[i]);
        i++;
      }
      j++;
    }

    return res;
  }
};
