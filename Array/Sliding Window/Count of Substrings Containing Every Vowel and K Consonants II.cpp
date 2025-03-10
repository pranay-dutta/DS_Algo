// Approach 1: Sliding Window
// T.C : O(2*n) ~ O(n)
// S.C : O(n)
class Solution {
 public:
  bool isVowel(char &c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
  long long countOfSubstrings(string word, int k) {
    int n = word.size();
    int lastConIdx = n;

    vector<int> nextCons(n); //SC: O(n)
    for (int i = n - 1; i >= 0; i--) { //TC: O(n)
      nextCons[i] = lastConIdx;
      if (!isVowel(word[i])) {
        lastConIdx = i;
      }
    }

    int i = 0, j = 0, con = 0;
    long long res = 0;
    unordered_map<char, int> mp; //SC: O(5)

    while (j < n) { //O(2n)
      char c = word[j];
      if (isVowel(c)) mp[c]++;
      else con++;

      while (con > k) {  // shink the window
        char c = word[i];
        if (isVowel(c)) {
          if (--mp[c] == 0) mp.erase(c);
        } else
          con--;
        i++;
      }

      // while window is valid
      while (i < n && mp.size() == 5 && con == k) {
        int nextConIdx = nextCons[j];
        char c = word[i];
        res += nextConIdx - j;

        if (isVowel(c)) {
          if (--mp[c] == 0) mp.erase(c);
        } else con--;

        i++;
      }

      j++;
    }
    return res;
  }
};
