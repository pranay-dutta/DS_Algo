// Approach 2:
// TC: O(n + 26) -> O(n)
// TC: O(1)
class Solution {
 public:
  int minimumLength(string s) {
    int n = s.length();
    int mp[26] = {0};

    for (int i = 0; i < n; i++) mp[s[i] - 'a']++;

    int ans = 0;
    for (int i = 0; i < 26; i++) {
      int freq = mp[i];
      if (freq && freq & 1) ans += 1;  // if odd
      else if (freq && ~freq & 1) ans += 2;  // if even
    }
    return ans;
  }
};
// Approach 1:
// TC: O(n + ~26) -> O(n)
// TC: O(1)
class Solution {
 public:
  int minimumLength(string s) {
    unordered_map<char, int> mp;     // SC: O(26)
    for (const char c : s) mp[c]++;  // TC: O(n)

    int ans = 0;
    for (auto [c, freq] : mp) {  // TC: O(26)
      if (freq > 1 && freq & 1) { ans += 1;
      } else if (freq > 2 && ~freq & 1) { ans += 2;
      } else ans += freq;  // freq than 2
    }
    return ans;
  }
};