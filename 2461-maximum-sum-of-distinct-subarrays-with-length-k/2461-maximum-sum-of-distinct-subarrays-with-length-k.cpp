class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long result = 0;
        long long  totalsum = 0;

        for(int i=0 ; i<k ; i++)
        {
            freq[nums[i]]++;
            totalsum+=nums[i];
        }
        
        if(freq.size() == k) result = totalsum;

        for(int j=k ; j<nums.size();j++)
        {
            freq[nums[j-k]]--;
            totalsum-=nums[j-k];

            if(freq[nums[j-k]] == 0)
            {
                freq.erase(nums[j-k]);
            }

            freq[nums[j]]++;
            totalsum+=nums[j];

if(freq.size() == k)
            result = max(result , totalsum);
        }


        return result;
    }
};