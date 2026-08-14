class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int totalsum = 0;
        int count = 0;
        unordered_map<int,int> freq;
        freq[0]++;
        for(int i=0 ; i<nums.size();i++)
        {
            totalsum+=nums[i];
            

            if(freq.find(totalsum - k) != freq.end())
            {
                count += freq[totalsum - k];
            }

            freq[totalsum]++;
        }
        return count;
       
    }
};