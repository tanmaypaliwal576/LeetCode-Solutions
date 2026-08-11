class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        
        for(int i=0 ; i<nums.size() ; i++)
        {
            totalsum += nums[i];
        }

        int leftsum = 0;
        for(int j = 0 ; j<nums.size() ; j++)
        {
            int rightsum = totalsum - leftsum - nums[j];
            if(leftsum==rightsum)
                return j;
            leftsum+=nums[j];
        }

        return -1;
        
        
    }
};