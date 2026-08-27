class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> expected = {
            {')' , '('},
            {']' , '['},
            {'}' , '{'}
        };

        unordered_set<char> open = {'{', '(', '['};
        unordered_set<char> close = {'}', ')', ']'};

        stack<char> ltrStack;
        for(char ltr:s) {
            if(close.find(ltr) != close.end() ) {
                if(ltrStack.empty() || expected[ltr] != ltrStack.top()) {
                    return false;
                }
                ltrStack.pop();
            }
            else if(open.find(ltr) == open.end()) {
                return false;
            }
            else {
                ltrStack.push(ltr);
            }
        }

        return ltrStack.empty();

    }
};
