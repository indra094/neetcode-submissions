class Solution {
public:


    vector<int> solve2(vector<int>& input) {
        vector<int> result(input.size(), 0);
        stack<int> ids;
        for(int id=0; id<input.size(); id++) {
            while(!ids.empty() && input[ids.top()]<input[id]) {
                result[ids.top()]=id-ids.top();
                ids.pop();
            }
            ids.push(id);
        }

        return result;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        return solve2(temperatures);
    }
};
