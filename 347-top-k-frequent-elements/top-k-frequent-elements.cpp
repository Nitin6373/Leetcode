class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        struct cmp {
            bool operator()(pair<int, int>& a, pair<int, int>& b) {
                if (a.second != b.second)
                    return a.second > b.second;
                return a.first < b.first;
            }
        };
        
        int n = nums.size();
        vector<int> Ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int,int> map;

        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }

        for(auto &p : map){
            int el = p.first;
            int freq = p.second;

            if(pq.size() == k){
                if(freq < pq.top().second)
                    continue;
                pq.pop();
            }

            pq.push({el,freq});
        }

        while(!pq.empty()){
            auto p = pq.top();
            Ans.push_back(p.first);
            pq.pop();
        }

        return Ans;
    }
};