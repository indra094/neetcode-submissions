class Solution {
public:

    bool isOp(const string& token) {
        return (token=="-" || token=="*" || token == "+" || token=="/");        
    }

    int calculate(int var1, int var2, const string& op) {
        if(op=="*") {
            return var1*var2;
        }
        else if(op=="-"){
            return var1-var2;
        }
        else if(op=="+"){
            return var1+var2;
        }
        else {
            return var1/var2;
        }
    }

    int solve1(vector<string>& tokens) {
        stack<int> vars;
        for(auto& word:tokens) {
            if(isOp(word)) {
                int var2 = vars.top();
                vars.pop();
                int var1 = vars.top();
                vars.top() = calculate(var1, var2, word);
                continue;
            }
            vars.push(stoi(word));
        }
        return vars.top();
    }

    int solve2(vector<string>& tokens) {
        
        int var1=-2, var2=-1;
        for(int op=0; op<tokens.size(); op++) {
         //   cout<<var1<<","<<var2<<'\n';
            if(isOp(tokens[op])) {
                
                tokens[var1] = to_string(calculate(stoi(tokens[var1]), stoi(tokens[var2]), tokens[op]));
                var2--, var1--;
            }
            else {
       
                var1++,var2++;
                tokens[var2]=tokens[op];
            }
        }
        //cout<<var2;
        return stoi(tokens[var2]);
    }

    int evalRPN(vector<string>& tokens) {
       // return solve1(tokens);
        return solve2(tokens);
    }
};
