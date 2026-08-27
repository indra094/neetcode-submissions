class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists(nums.begin(), nums.end());
        int maxLen = 0;
        for(int num: nums) {
            if(exists.find(num-1) == exists.end()) {
                int len = 1;
                while(exists.find(num+len) != exists.end()) {
                    len++;
                }
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }
};
