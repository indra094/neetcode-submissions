class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=-1, up=0, down=matrix.size()-1, col=-1,left=0,right=matrix[0].size()-1;

        while(up<=down) {
            int mid = up + (down-up)/2;
            if(matrix[mid][0]<= target && matrix[mid].back()>=target) {
                row = mid;
                break;
            }
            else if(matrix[mid][0]>target) {
                down = mid-1;
            }
            else {
                up = mid+1;
            }
        }

        if(row==-1) {
            return false;
        }

        auto itr = lower_bound(matrix[row].begin(), matrix[row].end(), target);
        if(itr == matrix[row].end() || *itr != target) {
            return false;
        }
        return true;
    }
};
