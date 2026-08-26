class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        
        int prod=1;
        for(int id=nums.size()-1; id>=0; id--) {
            result[id] *= prod;
            prod *=nums[id];
        }
        prod=1;
        for(int id=0; id<nums.size(); id++) {
            result[id]*=prod;
            prod *= nums[id];
        }

        return result;
    }
};
