class Solution {
public:
    void Fun(vector<int>& arr, vector<int>& t, int n, int i,
             vector<vector<int>>& res) {
        if (i == n) {
            res.push_back(t);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (find(t.begin(), t.end(), arr[j]) != t.end())
                continue;
            t.push_back(arr[j]);
            Fun(arr, t, n, i + 1, res);
            t.pop_back();
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> Res;
        vector<int> Temp;

        Fun(nums, Temp, nums.size(), 0, Res);

        return Res;
    }
};