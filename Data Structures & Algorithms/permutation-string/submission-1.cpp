class Solution {
public:

    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) {
            return false;
        }
        
        vector<int> s1Counts(26,0), currCounts(26,0);
        for(char ltr:s1){
            s1Counts[ltr-'a']++;
        }

        int id=0;
        for(; id<s1.size(); id++) {
            currCounts[s2[id]-'a']++;
        }
        if(currCounts==s1Counts) {
            return true;
        }

        for(; id<s2.size(); id++) {            
            currCounts[s2[id]-'a']++;
            currCounts[s2[id-s1.size()]-'a']--;
            if(currCounts==s1Counts) {
                return true;
            }
        }

        return false;
    }
};
