class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        struct cmp {
            bool operator()(pair<int, int>& a, pair<int, int>& b) {
                if (a.first != b.first)
                    return a.first < b.first;
                return a.second > b.second;
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        for (int i = 0; i < n; i++)
            pq.push({profits[i], capital[i]});

        vector<pair<int,int>> prev;

        while (!pq.empty()) {
            if(k == 0)
                break;
            auto p = pq.top();
            pq.pop();
            if(p.second > w){
                prev.push_back(p);
                continue;
            }
            w += p.first;
            k--;
            for(auto t : prev)
                pq.push(t);
            prev.clear();
        }
        return w;
    }
};