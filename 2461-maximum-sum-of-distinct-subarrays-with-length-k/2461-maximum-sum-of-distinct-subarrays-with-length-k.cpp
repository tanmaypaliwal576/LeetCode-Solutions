class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        long long totalsum = 0;
        long long ans = 0;
        for(int i =0 ; i<k ; i++)
        {
            totalsum+=nums[i];
            freq[nums[i]]++;
        }

        if(freq.size() == k) ans = totalsum;

        for(int j = k ; j<nums.size() ; j++)
        {
            freq[nums[j-k]]--;
            if(freq[nums[j-k]] == 0)
                freq.erase(nums[j-k]);
            totalsum+=nums[j];
            totalsum-=nums[j-k];
            freq[nums[j]]++;

            if(freq.size() == k) ans =  max(totalsum , ans);
        }

        return ans;

        
    }
};