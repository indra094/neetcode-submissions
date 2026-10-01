class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0, fast=0;
        while(slow != fast || slow ==0) {
            slow = nums[slow];
            fast = nums[nums[fast]];
           // cout<<slow<<fast<<'\n';
        }
       // cout<<"breal";
        slow = 0;
        while(slow != fast || slow ==0) {
            slow = nums[slow];
            fast = nums[fast];
           // cout<<slow<<fast<<'\n';
        }
        return slow;
    }
};
