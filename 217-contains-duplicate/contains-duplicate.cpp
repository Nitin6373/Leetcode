class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> f;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            f[nums[i]]++;
            if (f[nums[i]] > 1)
                return true;
        }

        return false;
    }
};