#include <vector>

using namespace std;

// Builds the 2D prefix sum grid
vector<vector<long long>> build_prefix_2D(int rows, int cols, const vector<vector<long long>>& grid) {
    vector<vector<long long>> pref(rows + 1, vector<long long>(cols + 1, 0));
    
    // Assuming 'grid' is 1-indexed
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i][j];
        }
    }
    return pref;
}

// Queries the sum of the subgrid from top-left (r1, c1) to bottom-right (r2, c2)
long long query_2D(const vector<vector<long long>>& pref, int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r1 - 1][c2] - pref[r2][c1 - 1] + pref[r1 - 1][c1 - 1];
}