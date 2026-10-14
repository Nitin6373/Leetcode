class Solution {
public:
    bool Helper(vector<int>& w, int d, int g) {
        int group = 1;
        int Sum = 0;

        for (int i = 0; i < w.size(); i++) {
            Sum += w[i];
            if (Sum > g) {
                group++;
                Sum = w[i];
            }
        }

        if (group <= d)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = -1;
        int high = 0;

        for (int i = 0; i < n; i++) {
            high += weights[i];
            low = max(weights[i], low);
        }

        int Ans = -1;

        while (low <= high) {
            int Guess = (low + high) / 2;
            if (Helper(weights, days, Guess)) {
                Ans = Guess;
                high = Guess - 1;
            } else
                low = Guess + 1;
        }

        return Ans;
    }
};