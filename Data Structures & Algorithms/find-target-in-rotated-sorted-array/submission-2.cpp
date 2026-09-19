class Solution {
public:
    int search(vector<int>& nums, int target) {
        int offset = 0;
        if(nums.size()!=1 && nums.front()>nums.back()) {
            int left = 0, right = nums.size()-1;
            while(left<=right) {
                int mid = left +(right-left)/2;
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
        }

        //cout<<offset<<" ";
        int left=0, right=nums.size()-1;
        while(left<=right) {
            int mid = (left+(right-left)/2);
            int midNum = nums[(offset+mid)%nums.size()];
            if(midNum==target) {
                return (offset+mid)%nums.size();
            }
            else if(midNum<target) {
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return -1;
    }
};
