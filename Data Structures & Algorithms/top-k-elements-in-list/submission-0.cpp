class Solution {
public:

   vector<int> findResult(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int num: nums) {
            counts[num]++;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        //1:3, 2:2, 3:1
        for(const pair<int, int>& entry: counts) {
            if(minHeap.size()==k && minHeap.top()[0]<entry.second) {
                minHeap.pop();
            }
            if(minHeap.size()<k) {
                minHeap.push({entry.second, entry.first});
            }
        }

        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top()[1]);
            minHeap.pop();
        }
        return result;
    }

    int partition(vector<int>& elems, const unordered_map<int, int>& counts, int left, int right) {
        int pos = left;

        int pivot = rand() % (right - left + 1) + left;
        swap(elems[pivot], elems[right]);
        // 1,2,3
        for(int id=left; id<right; id++) {
            if(counts.at(elems[id])>counts.at(elems[right])) {
                swap(elems[id], elems[pos]);
                pos++;
                
            }
        }
        //cout<<pos<<'\n';
        swap(elems[pos], elems[right]);

        return pos;
    }

    void quickSelect(vector<int>& elems, const unordered_map<int, int>& counts, int k) {
        int left =0, right =elems.size()-1;
        while(left<right) {
            int pos = partition(elems, counts, left, right);
            if(pos==k) {
                break;
            }
            if (pos<k) {
                left = pos+1;
            }
            else {
                right = pos-1;
            }
        }
    }

    vector<int> findResult2(vector<int>& nums, int k) {
        
        vector<int> result;
        unordered_map<int, int> counts;
        for(int num:nums) {
            counts[num]++;
        }
        vector<int> uniqueElems;
        for(const auto& entry:counts) {
            uniqueElems.push_back(entry.first);
        }
        if(k>=uniqueElems.size()) {
            return uniqueElems;
        }

        quickSelect(uniqueElems, counts, k-1);
        result.insert(result.end(), make_move_iterator(uniqueElems.begin()), make_move_iterator(uniqueElems.begin()+k));
        return result;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        result = findResult2(nums, k);

        return result;
    }

};
