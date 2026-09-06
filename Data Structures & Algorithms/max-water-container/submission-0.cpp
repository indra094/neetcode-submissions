class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0, right=heights.size()-1, maxArea=0;
        while(left<right) {
            maxArea=max(maxArea, min(heights[left], heights[right])*(right-left));
            if(heights[left]<heights[right]){
                left++;
            } else if(heights[right]<heights[left]) {
                right--;
            } else{
                left++;
                right--;
            }
        }

        return maxArea;
    }
};
