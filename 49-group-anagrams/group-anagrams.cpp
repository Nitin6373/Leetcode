class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> f;
        int n = strs.size();

        for(int i=0;i<n;i++){
            string value = strs[i];
            sort(strs[i].begin(),strs[i].end());
            f[strs[i]].push_back(value);
        }

        vector<vector<string>> Ans;

        for(auto &ele : f){
            Ans.push_back(ele.second);
        }

        return Ans;
    }
};