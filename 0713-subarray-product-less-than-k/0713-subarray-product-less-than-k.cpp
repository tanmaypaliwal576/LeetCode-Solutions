class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int right = 0;
       int left = 0;
       long long product = 1;
       int result = 0;

if(k <= 1)
    return 0;
    while(right<nums.size())
    {
        product*=nums[right];

        while(product >= k)
        {
            product/=nums[left];
            left++;
        }

        result += right - left + 1;
        right++;
        
    }


    return result;
    }
};