class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int inf = 0x3f3f3f3f;
        vector<int> dp(nums.size() + 1, inf);
        dp[0] = -inf;
        int answer = 0;
        for (const auto& num : nums) {
            int i = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            dp[i] = min(dp[i], num);
            answer = max(answer, i);
        }
        return answer;
    }
};
