class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> dp(150);
        for (const auto& letter : s) {
            int index = letter;
            int greater = 0;
            for (int i = index - k; i <= index + k; ++i)
                greater = max(greater, dp[i]);
            dp[index] = greater + 1;
        }
        return *max_element(dp.begin(), dp.end());
    }
};
