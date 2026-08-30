class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //return solve1(target, position, speed);
        return solve2(target, position, speed);
    }
    int solve2(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int> > posIDs;
        for(int id=0; id<position.size(); id++) {
            posIDs.push_back({position[id], id});
        }
        sort(posIDs.begin(), posIDs.end());

        stack<double> reachTimes;
        for(const auto& entry:posIDs) {
            double eta = double(target - entry.first)/speed[(entry.second)];
            while(!reachTimes.empty() && reachTimes.top()<=eta) {
                reachTimes.pop();
            }
            reachTimes.push(eta);
        }


        return reachTimes.size();
    }

    int solve1(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int> > posIDs;
        for(int id=0; id<position.size(); id++) {
            posIDs.push_back({position[id], id});
        }
        sort(posIDs.begin(), posIDs.end());

        double maxTime = 0;
        int fleetSize=position.size();
        for(int id=posIDs.size()-1; id>=0; id--) {
            double timeToReach = double(target - posIDs[id].first)/speed[posIDs[id].second];
         //   cout<<posIDs[id].second<<"->"<<posIDs[id].first<<" "<<timeToReach<<" ";

            if(timeToReach<=maxTime) {
                fleetSize--;
            }
            maxTime = max(maxTime, timeToReach);
        }

        return fleetSize;
    }
};
