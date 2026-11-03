class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // By Refering with Gpt

        vector<vector<int>> pairs;

        int n = position.size();

        for (int i = 0; i < n; i++) {
            pairs.push_back({position[i], speed[i]});
        }

        sort(pairs.rbegin(), pairs.rend());
        vector<float> Time;

        for (int i = 0; i < n; i++) {
            Time.push_back((target - pairs[i][0]) / (float)pairs[i][1]);
        }

        float prev = Time[0];
        int Ans = 1;

        for (int i = 1; i < n; i++) {
            if (Time[i] <= prev)
                continue;
            Ans++;
            prev = Time[i];
        }

        return Ans;
    }
};