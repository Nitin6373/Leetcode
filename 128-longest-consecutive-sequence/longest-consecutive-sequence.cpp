class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
            return n;

        sort(nums.begin(), nums.end());

        int Count = 0;
        int Ans = 0;

        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            if (i != 0 && nums[i] == (nums[i - 1] + 1))
                Count++;
            else {
                Ans = max(Count, Ans);
                Count = 1;
            }
        }
        Ans = max(Count,Ans);
        return Ans;
    }
};