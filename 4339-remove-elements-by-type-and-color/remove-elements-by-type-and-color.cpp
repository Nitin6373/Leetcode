class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors,
                      vector<int>& groupSize) {
        struct Group {
            int type;
            int color;
            int count;
        };

        stack<Group> st;
        int n = types.size();
        for (int i = 0; i < n; i++) {
            if (st.size() > 0 && st.top().type == types[i] &&
                st.top().color == colors[i]) {
                st.top().count++;
            } 
            else
                st.push({types[i], colors[i], 1});
            if (st.top().count == groupSize[st.top().type]) {
                st.pop();
            }
        }
        if (st.size() > 0)
            return false;
        return true;
    }
};