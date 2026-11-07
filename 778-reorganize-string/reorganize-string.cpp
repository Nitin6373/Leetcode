class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++) {
            map[s[i]]++;
        }

        struct cmp {
            bool operator()(pair<int, char>& a, pair<int, char>& b) {
                if (a.first != b.first)
                    return a.first < b.first;
                return a.second < b.second;
            }
        };
        priority_queue<pair<int, char>, vector<pair<int, char>>, cmp> pq;

        for (auto& p : map) {
            pq.push({p.second, p.first});
        }

        string Ans = "";
        pair<int, char> prev = {0, '0'};

        while (!pq.empty()) {
            auto pair = pq.top();
            pq.pop();
            Ans += pair.second;
            pair.first--;
            if (prev.first > 0)
                pq.push(prev);
            prev = pair;
        }

        return (prev.first > 0)?"":Ans;
    }
};