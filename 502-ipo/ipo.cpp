class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        priority_queue<int> pq;
        vector<pair<int,int>> project;

        for(int i=0;i<n;i++)
            project.push_back({capital[i],profits[i]});
        sort(project.begin(),project.end());

        int idx = 0;
        while(k--){
            while(idx < n){
                if(project[idx].first > w)
                    break;
                pq.push(project[idx].second);
                idx++;
            }
            if(pq.empty())
                return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};