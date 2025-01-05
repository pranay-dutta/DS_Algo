// Approach 1:
//  TC: O(n + m)
//  SC: O(n)
class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.length();
    vector<int> prefix(n + 1, 0);

    for (auto& shift : shifts) {  // O(m)
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2];
      prefix[start] += direction == 0 ? -1 : 1;
      prefix[end + 1] -= direction == 0 ? -1 : 1;
    }

    int currentShift = 0;
    for (int i = 0; i < n; i++) {  // O(n)
      currentShift = (currentShift + prefix[i]) % 26;  // moding to get range between 1 - 26
      s[i] = 'a' + (s[i] - 'a' + currentShift + 26) % 26;  // s[i]='a' {convert again to char 'a'} + ((a - 'a' = 0 + currentShift + 26) % 26)
    }

    return s;
  }
};
// Approach 2:
// TC: O(2n + m) -> O(n + m) 
// SC: O(n)
class Solution {
 private:
  char shift(char c, int val) { 
    return 'a' + ((c - 'a' + val % 26 + 26) % 26); 
  }

 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.length();
    vector<int> prefixSum(n, 0); //O(n)

    for (auto shift : shifts) { //O(m)
      int start = shift[0];
      int end = shift[1];
      int direction = shift[2];

      if (direction == 0) {
        prefixSum[start] += -1;
        if (end + 1 < n) prefixSum[end + 1] += 1;
      } else {
        prefixSum[start] += 1;
        if (end + 1 < n) prefixSum[end + 1] += -1;
      }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) { // O(n)
      sum += prefixSum[i];
      prefixSum[i] = sum;
    }

    for (int i = 0; i < n; i++) { //O(n)
      s[i] = shift(s[i], prefixSum[i]);
    }
    return s;
  }
};
