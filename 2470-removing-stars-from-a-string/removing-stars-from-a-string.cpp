class Solution {
public:
    string removeStars(string s) {
        string Ans = "";
        int n = s.size();
        for (char ch : s) {
            if (ch == '*' && !Ans.empty()) {
                Ans.pop_back();
                continue;
            }
            Ans.push_back(ch);
        }
        return Ans;
    }
};