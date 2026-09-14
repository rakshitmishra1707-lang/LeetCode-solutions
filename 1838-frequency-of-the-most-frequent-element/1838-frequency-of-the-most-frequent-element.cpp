class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        long long maxFreq = 0;
        long long l = 0, r = 0;
        long long total = 0;
        long long n = nums.size();

        for (r = 0; r < n; r++) {
            total += nums[r];

            while (l <= r && (long long)nums[r] * (r - l + 1) > total + k) {
                total -= nums[l];
                l++;
            }

            maxFreq = max(maxFreq, r - l + 1);
        }

        return maxFreq;
    }
};