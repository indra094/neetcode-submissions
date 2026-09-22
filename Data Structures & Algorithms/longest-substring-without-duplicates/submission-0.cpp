class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        int maxLen = 1, left = 0, right = 0;
        unordered_map<char, int> counts;
        counts[s[0]]++;
        while(right<s.size()) {
            if(counts[s[right]]>1) {
                counts[s[left]]--;
                left++;
                continue;
            }
            maxLen = max(maxLen, right- left+1);
            right++;
            if(right<s.size()) {
                counts[s[right]]++;
            }
        }

        return maxLen;
    }
};
