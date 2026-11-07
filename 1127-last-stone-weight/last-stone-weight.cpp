class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x = -1;
        int y = -1;

        priority_queue<int> pq;

        int n = stones.size();

        for(int i=0;i<n;i++)
            pq.push(stones[i]);

        while(pq.size() > 1){
            y = pq.top();
            pq.pop();
            x = pq.top();
            pq.pop();

            if(x == y)
                continue;
            
            pq.push(y-x);
        }

        return (pq.size())?pq.top():0;
    }
};