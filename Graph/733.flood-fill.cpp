#include<bits/stdtr1c++.h>
using namespace std;
/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) {
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        // Direction arrays for 4-way movement (Up, Right, Down, Left)
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            // Traverse all 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check boundaries and if the neighbor matches the original color
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && image[nrow][ncol] == originalColor) {
                    image[nrow][ncol] = color;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};
// @lc code=end

