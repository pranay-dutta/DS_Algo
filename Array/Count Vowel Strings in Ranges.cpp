class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    int n = words.size();
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    int count = 0;
    for (int i = 0; i < n; i++) {
      if (vowels.count(words[i].front()) && vowels.count(words[i].back())) {
        count++;
      }
      cumSum[i] = count;
    }

    vector<int> ans;
    for (auto &query : queries) {
      int l = query[0];
      int r = query[1];

      int wordCount = cumSum[r] - (l == 0 ? 0 : cumSum[l - 1]);

      ans.push_back(wordCount);
    }

    return ans;
  }
};
