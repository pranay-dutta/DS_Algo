//Approach-1 (Brute Force) 
//Simply try with every possible index at i and iterate on pattern and keep trying.
//T.C : O(m*n)
//S.C : O(1)


//Approach-2 (KMP Algorithm)
//T.C : O(m+n)
//S.C : O(m) where m is the length of pattern
/**
 * @param pattern The master text
 * @param text The text you want search in the master
 * @return The indexes where text found in the master
 */
class Solution {
 public:
  vector<int> KMP(string &pattern, string &text) {
    int n = pattern.length();
    int m = text.length();

    vector<int> LPS(m);  // longest prefix and suffix in text(subtring you want to match)

    /*.....Calcuate LPS......*/
    LPS[0] = 0;
    for (int i = 1; i < m; i++) {
      int len = LPS[i - 1];

      // If current character matches with the next character in pattern,
      // increment LPS[i]
      while (len > 0 && text[i] != text[len]) {
        len = LPS[len - 1];
      }
      if (text[i] == text[len]) len++;  // increase LPS[i] because it matches the next character in pattern
      LPS[i] = len;
    }

    int i = 0, j = 0;
    vector<int> idxs_whre_text_found;
    while (i < n) {
      if (pattern[i] == text[j]) {
        i++; j++;
      } else {
        if(j != 0) j = LPS[j - 1];
        else i++;  // j can't be negative so move i
      }

      //text found in pattern
      if (j == m) {  // match found
        idxs_whre_text_found.push_back(i - j);
        j = LPS[j - 1];  // reset j to match the next character in pattern
      } 
    }
    return idxs_whre_text_found;
  }
};