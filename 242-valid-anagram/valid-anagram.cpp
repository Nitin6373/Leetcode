class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fs;
        unordered_map<char, int> ft;

        int ns = s.size();
        int nt = t.size();

        if (ns != nt)
            return false;

        for (int i = 0; i < ns; i++) {
            fs[s[i]]++;
        }

        for (int i = 0; i < nt; i++) {
            ft[t[i]]++;
        }

        for(auto &ch : ft){
            int c = ch.first;
            int cFreqT = ch.second;
            int cFreqS = fs[c];

            if(cFreqT != cFreqS)
                return false;
        }

        return true;
    }
};