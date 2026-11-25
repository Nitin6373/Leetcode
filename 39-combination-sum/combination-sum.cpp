class Solution {
public:
    void Fun(int idx, int n, vector<int>& arr, int target, int Sum,
             vector<int> Diary, vector<vector<int>>& Res) {
        if (idx == n) {
            if (Sum == target)
                Res.push_back(Diary);
            return;
        }

        Fun(idx + 1, n, arr, target, Sum, Diary, Res);

        if (arr[idx] + Sum <= target) {
            Diary.push_back(arr[idx]);
            Sum += arr[idx];
            Fun(idx, n, arr, target, Sum, Diary, Res);
            Diary.pop_back();
            Sum -= arr[idx];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> Res;
        vector<int> Diary;

        Fun(0, candidates.size(), candidates, target, 0, Diary, Res);
        return Res;
    }
};