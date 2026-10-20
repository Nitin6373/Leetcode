class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> f;

        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
        }

        vector<vector<int>> Temp;

        for (auto& key : f) {
            int Element = key.first;
            int freq = key.second;
            Temp.push_back({Element, freq});
        }

        sort(Temp.begin(), Temp.end(),
             [](auto a, auto b) { return a[1] > b[1]; });

        vector<int> Ans;

        for (int i = 0; i < k; i++) {
            Ans.push_back(Temp[i][0]);
        }

        return Ans;
    }
};