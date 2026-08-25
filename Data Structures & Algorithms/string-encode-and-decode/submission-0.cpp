class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(auto word: strs) {
            encoded += to_string(word.size())+"-"+word;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int pos = s.find('-');
        while(pos != string::npos) {
            int len = stoi(s.substr(0, pos));
            result.push_back(s.substr(pos+1, len));
            s = s.substr(pos+1+len);
            pos=s.find('-');
        }

        return result;
    }
};
