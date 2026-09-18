class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums.size()==1 || nums.front()<nums.back()) {
            return nums.front();
        }

        int offset=0, left=0, right=nums.size()-1;
        while(left<=right) {
            int mid = (left+right)/2;
            if(nums[mid]>nums[(mid+1)%nums.size()]) {
                offset = mid+1;
                break;
            }
            else if(nums[mid]<nums.front() && nums[mid]<nums.back()) {
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
        return nums[offset%nums.size()];
    }
};
