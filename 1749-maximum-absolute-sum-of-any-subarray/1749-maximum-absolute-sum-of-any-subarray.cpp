class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int minsum = nums[0];
        int currentmaxsum = nums[0];
        int currentminsum = nums[0];
        for(int i= 1 ; i<n;i++)
        {
            currentmaxsum = max(nums[i] , nums[i] + currentmaxsum);
            maxsum = max(currentmaxsum , maxsum);

            currentminsum = min(nums[i] , nums[i] + currentminsum);
            minsum = min(currentminsum , minsum);
        }

        int ans = max(abs(minsum) , maxsum);
        return ans;
    }
};