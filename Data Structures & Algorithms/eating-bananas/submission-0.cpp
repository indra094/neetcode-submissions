class Solution {
public:

    int calculateTimeToFinish(const vector<int>& piles, int speed) {
        int time=0;
        if(speed == 0 || speed == INT_MAX) {
            return 0;
        }
        for(int pile:piles) {
            time+=ceil(double(pile)/speed);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        int left = 1, right = maxPile, minSpeed=maxPile;
        while(left<=right) {
            int mid = left+(right-left)/2;
            int midTime = calculateTimeToFinish(piles, mid);
            
            
            if(midTime <= h) {
                minSpeed = mid;
                right = mid - 1;
            }
            else {
                left = mid+1;
            }
        }
        return minSpeed;
    }
};
