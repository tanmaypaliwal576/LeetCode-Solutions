class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        unordered_map<int,int> freq;
        freq[0] = -1;
        for(int i=0; i<nums.size();i++)
        {
            prefix+=nums[i];

            int value = prefix % k ;

            if(freq.find(value)!=freq.end())
            {
                if(i - freq[value] >=2)
                    return true;
            }
            else
            {
                freq[value] = i;
            }

        }
        return false;
    }
};