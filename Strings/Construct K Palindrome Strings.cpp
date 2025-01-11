// Approach 1:
// TC: O(n + u) -> O(n)
// SC: O(n)
class Solution {
 public:
  bool canConstruct(string s, int k) {
    int n = s.length();
    if (n < k) return 0;  // if n < k it's also impossible to create k number of // palindromes

    unordered_map<char, int> mp;  // O(n)
    int odd = 0;

    // with even numbers you can create as many palindrome as possible if (n > k)
    for (int i = 0; i < n; i++) {  // O(n)
      mp[s[i]]++;
    }

    // But if odd frequency is greater than 'k' then it's impossible to create 'k' number of palindromes
    for (auto p : mp) {  // O(u) -> O(26)
      if (p.second % 2 == 1) odd++;
    }
    return odd <= k;
  }
};
