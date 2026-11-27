class Solution {
public:
    bool isPalindrome(string& arr) {
        int low = 0;
        int n = arr.size();
        if (n <= 1)
            return true;
        int high = n - 1;
        while (low <= high) {
            if (arr[low] == arr[high]) {
                low++;
                high--;
                continue;
            }
            return false;
        }
        return true;
    }
    void Fun(vector<string>& diary, vector<vector<string>>& Res, int idx, int n,
             string& arr) {
        if (idx == n) {
            Res.push_back(diary);
            return;
        }
        string Temp = "";
        for (int i = idx; i < n; i++) {
            Temp.push_back(arr[i]);
            if (isPalindrome(Temp)) {
                diary.push_back(Temp);
                Fun(diary, Res, idx + Temp.size(), n, arr);
                diary.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> Res;
        vector<string> Diary;
        Fun(Diary, Res, 0, s.size(), s);
        return Res;
    }
};