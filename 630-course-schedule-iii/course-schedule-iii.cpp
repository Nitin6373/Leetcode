class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        priority_queue<int> pq;

        int Start = 0;
        for (int i = 0; i < n; i++) {
            cout << courses[i][0] << ":" << courses[i][1] << endl;

            pq.push(courses[i][0]);
            Start += courses[i][0];
            if (Start > courses[i][1]) {
                Start -= pq.top();
                if (Start < 0)
                    Start = 0;
                pq.pop();
            }
        }
        return pq.size();
    }
};