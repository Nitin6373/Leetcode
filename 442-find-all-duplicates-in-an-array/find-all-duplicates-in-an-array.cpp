class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> Ans;
        unordered_map<int,int> fs;

        int n = nums.size();
        for(int i=0;i<n;i++){
            fs[nums[i]]++;
            if(fs[nums[i]] > 1){
                Ans.push_back(nums[i]);
            }
        }

        return Ans;
    }
};