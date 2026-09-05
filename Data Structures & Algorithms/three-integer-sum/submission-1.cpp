class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> pairList, result;
        for(int id=0; id<nums.size(); id++) {
            pairList.push_back({nums[id], id});
        }

        sort(pairList.begin(), pairList.end());

        
        for(int id=0; id<nums.size()-2; id++) {
            if(id==0 || pairList[id-1][0] != pairList[id][0]) {
                twoSum(id, id+1, pairList, result);
            }
        }
        return result;
    }

    void twoSum(int id, int left, const vector<vector<int>>& pairs, vector<vector<int>>& result) {
        int right = pairs.size()-1;
        while(left<right) {
            int sum =pairs[left][0]+pairs[right][0];
            if(left==id+1 || pairs[left][0]!=pairs[left-1][0]) {
                if(sum<-pairs[id][0]) {
                    left++;
                } else if(sum>-pairs[id][0]) {
                    right--;
                } else {
                    result.push_back({pairs[id][0], pairs[left][0], pairs[right][0]});
                    left++;
                    right--;
                }
                continue;
            }
            left++;
        }
    }
};
