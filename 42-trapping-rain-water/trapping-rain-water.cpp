class Solution {
public:
    int trap(vector<int>& height) {
        int m = INT_MIN;
        int n = height.size();
        int Left[n];
        int Right[n];

        Left[0] = height[0];
        m = height[0];
        for(int i=1;i<n;i++){
            m = max(m,height[i]);
            Left[i] = m;
        }

        Right[n-1] = height[n-1];
        m = height[n-1];
        for(int i=n-2;i>=0;i--){
            m = max(m,height[i]);
            Right[i] = m;
        }

        int Ans = 0;
        for(int i=0;i<n;i++){
            Ans += max(0,(min(Left[i],Right[i]) - height[i]));
        }

        return Ans;
    }
};