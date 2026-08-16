class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int totalsum = nums[0];
        int maxsum = nums[0];
        int minsum = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];
        for(int i=1; i<n;i++)
        {
            totalsum+=nums[i];
            currentMax = max(nums[i], currentMax + nums[i]);
            maxsum = max(maxsum, currentMax);

            currentMin = min(nums[i], currentMin + nums[i]);
            minsum = min(minsum, currentMin);
        }

        int ans = totalsum - minsum;

        if(maxsum<0) return maxsum;

        return max(ans , maxsum);
    }
};