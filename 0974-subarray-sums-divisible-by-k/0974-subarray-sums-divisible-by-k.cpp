class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int , int> freq;
        freq[0]++;
        int count = 0;
        int prefix= 0;
        for(int i = 0 ; i<nums.size();i++)
        {
            prefix += nums[i];
            int rem = prefix % k;

            if(rem < 0) //for negative remainders
            {
                rem = ((prefix % k) + k) % k; //also (rem += k;) can be used
            }
            if(freq.find(rem)!=freq.end())
            {
                count += freq[rem];
            }

            freq[rem]++;
        }   
    
        return count;
    }   
};