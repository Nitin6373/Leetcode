class Solution {
public:
    void Fun(vector<char>& str, int low, int high) {
        int len = high - low + 1;
        if (len == 0 || len == 1)
            return;
        char ch = str[low];
        str[low] = str[high];
        str[high] = ch;

        Fun(str, low + 1, high - 1);
        return;
    }
    void reverseString(vector<char>& s) { Fun(s, 0, s.size() - 1); }
};