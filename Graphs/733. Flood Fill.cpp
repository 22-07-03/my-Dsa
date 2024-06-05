#pragma GCC optimize("03")
#include <vector>
using namespace std;

#define vvi vector<vector<int>> 
#define vi vector<int>

class Solution {
public:
    void dfs(int& row, int& col, vvi& newimage, vvi& image, vi& rowdirections, vi& coldirections, int& initialcolor, int& color) {
        newimage[row][col] = color;

        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + rowdirections[i];
            int ncol = col + coldirections[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialcolor && newimage[nrow][ncol] != color) {
                dfs(nrow, ncol, newimage, image, rowdirections, coldirections, initialcolor, color);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
        int initialcolor = image[sr][sc];
        vector<int> rowdirections = {-1, 0, 1, 0};
        vector<int> coldirections = {0, 1, 0, -1};
        vvi newimage = image;

        if (initialcolor != color) {
            dfs(sr, sc, newimage, image, rowdirections, coldirections, initialcolor, color);
        }

        return newimage;
    }
};
