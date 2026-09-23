class Solution {
public:
    int characterReplacement(string s, int k) {
        int right=0, left=0;
        vector<int> counts(26, 0);
        counts[s[0]-'A']++;
        int maxLen=1;
        while(right<s.size()) {
            int len = right-left+1;
            int maxElem = *max_element(counts.begin(), counts.end());

            if(len-maxElem>k) {
                counts[s[left]-'A']--;
                left++;
                continue;
            }

            maxLen = max(maxLen, len);
            right++;
            if(right<s.size()) {
                counts[s[right]-'A']++;
            }
            
        }
        return maxLen;
    }
};
