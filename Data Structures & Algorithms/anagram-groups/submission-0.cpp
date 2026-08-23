class Solution {
    string findAnagramKey(const string& word) {
        vector<int> counts(26);
        for(char ltr:word) {
            counts[ltr-'a']++;
        }
        string key;
        for(int count:counts) {
            key += "," + to_string(count);
        }
        return key;
    }
public:


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > anagramGroups;
        for(string word:strs) {
            string key = findAnagramKey(word);
            anagramGroups[key].push_back(word);
        }

        vector<vector<string>> result;
        for(const auto& entry: anagramGroups) {
            result.push_back(entry.second);
        }
        return result;
    }
};
