class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> posStack;
        for(int id=0; id<heights.size(); id++) {
            while(!posStack.empty() && heights[id]<=heights[posStack.top()]) {
                int topPos=posStack.top();
                posStack.pop();
                maxArea = max(maxArea, ((topPos-(posStack.empty()?-1:posStack.top()))+(id-topPos)-1)*heights[topPos]);
             //   cout<<maxArea<<" ";
                
            }
            int prevPos = posStack.empty()?-1:posStack.top();
            maxArea = max(maxArea, (id-prevPos)*heights[id]);
            posStack.push(id);
        }

        while(!posStack.empty()) {
            int topPos=posStack.top();
            posStack.pop();
            maxArea = max(maxArea, int((topPos-(posStack.empty()?-1:posStack.top()))+(heights.size()-topPos)-1)*heights[topPos]);
            //cout<<heights[posStack.top()]<<heights.size()-posStack.top();
            
        }

        return maxArea;
    }
};
