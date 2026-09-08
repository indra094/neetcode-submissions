class Solution {
public:
    int trap(vector<int>& height) {
        int occupied=0, total=0, left =0, right=height.size()-1;
        for(int id=1; id<height.size(); id++) {
            if(height[id]>=height[left]) {
                total+=(min(height[id], height[left]) * (id-left-1))-occupied;
                occupied=0;
               // cout<<total<<" ";
                left = id;
                continue;
            }
            occupied+=height[id];
        }

        occupied = 0;
        for(int id=height.size()-2; id>=left; id--) {
            if(height[id]>=height[right]) {
                total+=(min(height[id], height[right]) * (right-id-1))-occupied;
                occupied=0;
              //  cout<<total<<" ";
                right = id;
                continue;
            }
            occupied+=height[id];
        }

        return total;
    }
};
