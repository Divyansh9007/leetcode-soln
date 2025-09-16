class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '0'; // mark visited directly

        int nrow[] = {0, -1, 0, 1};
        int ncol[] = {-1, 0, 1, 0};

        while (!q.empty()) {
            int rowNumber = q.front().first;
            int colNumber = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int calcRow = nrow[i] + rowNumber;
                int calcCol = ncol[i] + colNumber;

                if (calcRow >= 0 && calcRow < grid.size() &&
                    calcCol >= 0 && calcCol < grid[0].size() &&
                    grid[calcRow][calcCol] == '1') {
                    
                    q.push({calcRow, calcCol});
                    grid[calcRow][calcCol] = '0'; // mark visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    bfs(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
