class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int sum = nums[0];
        int currentmax = nums[0];
        for(int i=1 ; i<nums.size();i++)
        {
            currentmax = max(nums[i] , nums[i] + currentmax);
            maxsum = max(currentmax , maxsum);
        }

        return maxsum;

       
    }
};