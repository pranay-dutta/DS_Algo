// Approach 1:
// TC: O(n)
// SC: O(n•log(n))

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();

    vector<int> temp = nums;
    sort(begin(temp), end(temp));  // O(n•log(n))

    unordered_map<int, int> mp;  //{element with group id} //O(n)
    int groupNum = 0;
    mp[temp[0]] = groupNum;  // first element coordinate

    unordered_map<int, list<int>> groups;  //{groups of simillar limit}
    groups[groupNum].push_back(temp[0]);

    for (int i = 1; i < n; i++) {  // O(n)
      if (abs(temp[i] - temp[i - 1]) > limit) {
        groupNum += 1;
      }
      mp[temp[i]] = groupNum;
      groups[groupNum].push_back(temp[i]);
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++) {  // O(n)
      int groupId = mp[nums[i]];

      result[i] = *groups[groupId].begin();
      groups[groupId].pop_front();
    }
    return result;
  }
};
