class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freq = 0;
        int count = 0;
        int maxnum =0;
        int left=0;
        int right = 0;
        while(right < nums.size())
        {
            if(nums[right] == 0)
            {
                freq++;
            }
            right++;
            while(freq > k)
            {
                if(nums[left] == 0)
                    freq--;
                
                left++;
            }
           
            maxnum = max(right - left , maxnum);
        }

        return maxnum;
    }
};