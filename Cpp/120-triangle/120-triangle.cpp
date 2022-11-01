class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i)
            triangle[i][0] += triangle[i - 1][0];
        for (int i = 1; i < triangle.size(); ++i)
            for (int j = 1; j < triangle[i].size(); ++j)
                triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][min(i - 1, j)]);
        
        return *min_element(triangle.back().begin(), triangle.back().end());
    }
};
