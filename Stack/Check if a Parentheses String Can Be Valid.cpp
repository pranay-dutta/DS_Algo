// Approach 1:
// TC: O(1)
// SC: O(1)
class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n & 1) return false;  // odd string length can't pair

    int open = 0;   // count of opening brackets
    int close = 0;  // count of closing brackets

    for (int i = 0, j = n - 1; i < n; j--, i++) {  // TC: O(n)

      if (s[i] == '(' || locked[i] == '0') open++;  //[L->R] consider 'opening' and 'not-locked' brackets as opening brackets
      if (s[i] == ')' && locked[i] == '1') open--;

      if (s[j] == ')' || locked[j] == '0') close++;  //[L<-R] consider 'closing' and 'not-locked' brackets as opening brackets
      if (s[j] == '(' && locked[j] == '1') close--;

      if (open < 0 || close < 0) return false;
    }

    return true;
  }
};


// Approach 1:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  bool canBeValid(string s, string locked) {
    int n = s.size();
    if (n & 1) return false;

    stack<int> openBrackets;  // SC: ~ O(n/2)
    stack<int> openClose;     // SC: ~ O(n/2)

    for (int i = 0; i < n; i++) {  // TC: ~O(n/2)
      if (s[i] == '(' && locked[i] == '1') openBrackets.push(i);
      else if (locked[i] == '0') openClose.push(i);
      else {  // s[i] == ')'
        if (!openBrackets.empty()) openBrackets.pop();
        else if (!openClose.empty()) openClose.pop();
        else return false;
      }
    }

    while (!openClose.empty() && !openBrackets.empty() && openClose.top() > openBrackets.top()) {  // TC: ~ O(n/2)
      openClose.pop();
      openBrackets.pop();
    }
    return openBrackets.empty();
  }
};