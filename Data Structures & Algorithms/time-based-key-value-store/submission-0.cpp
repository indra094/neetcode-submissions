class TimeMap {

    unordered_map<string, vector<pair<int, string>> > timeMap;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeMap[key].empty()) 
        {
            return "";
        }
        vector<pair<int, string>>::iterator itr = upper_bound(timeMap[key].begin(), timeMap[key].end(), make_pair(timestamp, ""),
        [](const pair<int, string>& elem1, const pair<int, string>& elem2) {
            return elem1.first<elem2.first;
        });

        if(itr == timeMap[key].begin()) {
            return "";
        }


        return prev(itr)->second;
    }
};
