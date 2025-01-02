//TC: O(max(m, n))
//TC: O(1) :Excluding output
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length(), m = word2.length(), i = 0, j = 0;
        string merged;
        while(1) {
            if(i < n) merged += word1[i++];
            if(j < m) merged += word2[j++];
            if(i == n && j == m) break;
        }
        return merged;
    }
};
