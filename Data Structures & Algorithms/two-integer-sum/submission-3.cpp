class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ids;
        for(int id=0; id<nums.size(); id++) {
            if(ids.count(target-nums[id]) != 0) {
                return {ids[target-nums[id]], id};
            }
            ids[nums[id]]=ids[nums[id]]==0?id:min(ids[nums[id]], id);
        }
        return {0,0};
    }
};
