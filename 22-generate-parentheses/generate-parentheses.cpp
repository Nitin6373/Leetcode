class Solution {
public:
    void Fun(int open, int close, int n, vector<string>& ans, string& temp) {
        if (open == n && close == n){
            ans.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            Fun(open + 1, close, n, ans, temp);
            temp.pop_back();
        }

        if (close < open) {
            temp.push_back(')');
            Fun(open, close + 1, n, ans, temp);
            temp.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string Temp;
        Fun(0, 0, n, ans, Temp);
        return ans;
    }
};