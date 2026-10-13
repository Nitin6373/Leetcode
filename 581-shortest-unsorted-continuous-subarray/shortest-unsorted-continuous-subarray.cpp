class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        if(n <= 1)
            return 0;

        int End = 0;
        int Max = nums[0];
        
        for(int i=1;i<n;i++){
            if(Max <= nums[i])
                Max = nums[i];
            else 
                End = i;
        }

        if(End == 0)
            return 0;

        int Start = n-1;
        int Min = nums[n-1];

        for(int i=n-2;i>=0;i--){
            if(Min >= nums[i])
                Min = nums[i];
            else 
                Start = i;
        }

        return End - Start + 1;
    }
};