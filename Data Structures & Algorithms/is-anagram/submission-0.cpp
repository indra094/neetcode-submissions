class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> sCounts, tCounts;
        for(int id=0; id<t.size(); id++) {
            sCounts[s[id]]++;
            tCounts[t[id]]++;
        }
        for(auto entry:sCounts) {
            if(entry.second != tCounts[entry.first]) {
                return false;
            }
        }
        return true;
    }
};
