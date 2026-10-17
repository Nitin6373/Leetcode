class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '*' && !st.empty()) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

        string Ans = "";

        while(!st.empty()){
            Ans += st.top();
            st.pop();
        }

        reverse(Ans.begin(),Ans.end());

        return Ans;
    }
};