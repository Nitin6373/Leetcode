class Solution {
public:
    bool Helper(vector<int>& c, long long k, long long g) {
        long long count = 0;
        int n = c.size();

        for (int i = 0; i < n; i++) {
            count += c[i] / g;
        }

        if (count >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1;
        int high = 0;
        int n = candies.size();
        int Ans = 0;

        for (int i = 0; i < n; i++) {
            high = max(high,candies[i]);
        }

        while (low <= high) {
            long long guess = (low + high) / 2;
            if (Helper(candies, k, guess)) {
                Ans = guess;
                low = guess + 1;
            } else
                high = guess - 1;
        }

        return Ans;
    }
};