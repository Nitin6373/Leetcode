class Solution {
public:
    bool Helper(vector<vector<int>> value, int i, int j, int boxI, int boxJ) {
        for (int r = 0; r < value.size(); r++) {
            if (value[r][0] == i || value[r][1] == j ||
                (value[r][2] == boxI && value[r][3] == boxJ))
                return true;
        }
        return false;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = 9;
        int n = 9;
        unordered_map<int, vector<vector<int>>> map;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j];
                    int boxI = i / 3;
                    int boxJ = j / 3;

                    if (map.find(digit) != map.end()) {
                        // Key exits
                        if (Helper(map[digit], i, j, boxI, boxJ)) {
                            return false;
                        }
                    }
                    map[digit].push_back({i, j, boxI, boxJ});
                }
            }
        }

        return true;
    }
};