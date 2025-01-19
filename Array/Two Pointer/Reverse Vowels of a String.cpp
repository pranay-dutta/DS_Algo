// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
  string reverseVowels(string s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
      while (l < r && !isVowel(s[l])) l++;
      while (r > l && !isVowel(s[r])) r--;

      swap(s[l], s[r]);
      l++, r--;
    }
    return s;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(10) ->  O(1)
class Solution {
 public:
  string reverseVowels(string s) {
    string vowels = "aeiouAEIOU";
    unordered_set<char> se(begin(vowels), end(vowels));
    int l = 0, r = s.length() - 1;
    while (l < r) {
      while (l < r && !se.count(s[l])) l++;
      while (r > l && !se.count(s[r])) r--;

      if (l < r) {
        swap(s[l], s[r]);
        l++, r--;
      }
    }
    return s;
  }
};
