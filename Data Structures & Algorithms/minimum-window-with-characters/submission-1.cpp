class Solution {
public:
    bool includest(const unordered_map<char, int>& counts1, const unordered_map<char, int>& counts2) {
        for(const auto& entry: counts2) {
            auto ref = counts1.find(entry.first);
            if(ref == counts1.end() || ref->second<entry.second) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.size()<t.size()) {
            return "";
        }
        unordered_map<char, int> currCounts, tCount;
        for(char ltr:t) {
            tCount[ltr]++;
        }

        int left=0, right=0, minLeft=0, minRight=INT_MAX;
        currCounts[s.front()]++;
        bool found = false;
        while(right<s.size()) {
            if(includest(currCounts, tCount)) {
                found = true;
                if(right-left+1<minRight-minLeft+1) {
                    minLeft = left;
                    minRight = right;
                }
                currCounts[s[left]]--;
                left++;
                continue;
            }

            right++;
            if(right<s.size()) {
                currCounts[s[right]]++;
            }
        }

        return found?s.substr(minLeft, minRight-minLeft+1):"";
    }
};
