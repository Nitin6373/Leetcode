class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        struct cmp {
            bool operator()(pair<int, char>& a, pair<int, char>& b) {
                if (a.first != b.first)
                    return a.first < b.first;
                return a.second > b.second;
            }
        };

        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;
        queue<pair<char, pair<int, int>>> q;
        unordered_map<char, int> map;

        for (int i = 0; i < m; i++)
            map[tasks[i]]++;

        for (auto& p : map)
            pq.push({p.second, p.first});

        int Count = 0;
        while (!q.empty() || !pq.empty()) {
            if (!q.empty() && q.front().second.second <= Count) {
                auto qpair = q.front();
                q.pop();
                pq.push({qpair.second.first, qpair.first});
            }
            if (!pq.empty()) {
                auto pair = pq.top();
                pq.pop();
                pair.first--;
                if (pair.first > 0)
                    q.push({pair.second, {pair.first, Count + n + 1}});
            }
            Count++;
        }
        return Count;
    }
};