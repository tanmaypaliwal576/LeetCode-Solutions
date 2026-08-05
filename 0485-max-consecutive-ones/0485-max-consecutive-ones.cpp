class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxnum = 0;
        for(int i = 0; i<nums.size() ; i++)
        {
           
            if(nums[i] == 1)
            {
                count++;
            }
            else
            {
                maxnum = max(count , maxnum);
                count = 0;
            }
        }
        int result = max(count , maxnum);
        return result;
    }
};