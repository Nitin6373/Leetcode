class Solution {
public:
    void Fun(string& que, int n, int idx, string& diary, vector<string>& map,
             vector<string>& ans) {
        if (idx == n) {
            ans.push_back(diary);
            return;
        }
        string T = map[que[idx] - '0'];
        int tsize = T.size();
        for (int i = 0; i < tsize; i++) {
            diary.push_back(T[i]);
            Fun(que, n, idx + 1, diary, map, ans);
            diary.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> Letters = {
            " ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        string diary = "";
        vector<string> ans;
        Fun(digits, digits.size(), 0, diary, Letters, ans);
        return ans;
    }
};