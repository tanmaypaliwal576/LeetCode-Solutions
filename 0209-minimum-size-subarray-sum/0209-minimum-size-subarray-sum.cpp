class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int left = 0;
        int size = INT_MAX;
        int totalsum  = 0;

        while(right<nums.size())
        {
             totalsum+=nums[right];

            while(totalsum >= target)
            {
            
                size = min(right - left + 1,size);
                totalsum-=nums[left];
                left++;
            }


           
            


            right++;
        }
 if(size == INT_MAX) return 0;

        return size;
    }
};