class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ids;
        int left=0, right=numbers.size()-1;
        while(left<=right) {
            if(numbers[left]+numbers[right]==target) {
                ids = {left+1,right+1};
                break;
            }
            else if(numbers[left]+numbers[right]<target) {
                left++;
            }
            else {
                right--;
            }
        }
        return ids;
    }
};
