class Solution {
public:
    string digitSum(string s, int k) {
        int n;
        vector<string> strs;
        strs.push_back(s);
        int i = 0;
        s = "";
        while (strs[i].size() > k) {
            n = strs[i].size();
            int sum = 0;
            int c = 0;
            for (int j = 0; j < n; j++) {
                sum += strs[i][j] - '0';
                c++;

                if (c == k) {
                    s += to_string(sum);
                    c = 0;
                    sum = 0;
                }
            }
            if (c != 0) {
                s += to_string(sum);
                c = 0;
                sum = 0;
            }
            cout << s << endl << endl;
            strs.push_back(s);
            s = "";
            i++;
        }

        return strs[strs.size() - 1];
    }
};