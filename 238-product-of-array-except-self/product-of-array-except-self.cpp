class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int Pre[n];
        int Suf[n];

        Pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            Pre[i] = nums[i] * Pre[i - 1];
        }

        Suf[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            Suf[i] = Suf[i + 1] * nums[i + 1];
        }

        vector<int> Ans;
        Ans.push_back(Suf[0]);

        for (int i = 1; i < n; i++) {
            Ans.push_back(Suf[i] * Pre[i - 1]);
        }

        return Ans;
    }
};