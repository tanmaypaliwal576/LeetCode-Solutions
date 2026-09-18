class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmostk(nums,k) - atmostk(nums , k-1);
    }
    int atmostk(vector<int>& nums, int k)
{
     int right = 0;
    int left = 0;
        unordered_map<int,int> freq;
        int count = 0;
        while(right<nums.size())
        {
            freq[nums[right]]++;
            while(freq.size() > k)
            {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) 
                    freq.erase(nums[left]);
                
                left++;
            }
           count+=right-left+1;

            right++;
        }


        return count;
}
};

