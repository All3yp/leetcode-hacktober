class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        const int INF = 0x3f3f3f3f;
        vector<int> dp(nums.size() + 1, INF);
        vector<set<int>> possibilitiesNums(nums.size() + 1);
        int length = 0;
        dp[0] = -INF;
        for (const auto& num : nums) {
            int i = lower_bound(dp.begin(), dp.end(), num) - dp.begin();
            if (i > 1) {
                bool ok;
                do {
                    auto it = possibilitiesNums[i - 1].insert(num).first;
                    auto previousIt = it; --previousIt;
                    ok = *previousIt + k >= num;
                    possibilitiesNums[i - 1].erase(it);
                    if (!ok) --i;
                } while (!ok && i > 0);
            }
            dp[i] = min(dp[i], num);
            possibilitiesNums[i].insert(num);
            length = max(length, i);
        }
        return length;
    }
};
