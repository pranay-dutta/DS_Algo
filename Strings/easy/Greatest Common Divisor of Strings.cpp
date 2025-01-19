// Approach 1:
// TC: O(max(m, n))
// SC: O(1
class Solution {
 public:
  string gcdOfStrings(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    int GCD = gcd(m, n);
    return s1 + s2 == s2 + s1 ? s1.substr(0, GCD) : "";  // TC: O(n + m) string comparison
  }
};
