class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int prefixsum = 0;
        unordered_map<int,int> freq;
        freq[0]++;
        int count = 0;

        for(int i=0; i<nums.size() ; i++)
        {
            prefixsum = prefixsum+ nums[i];
         
             if(freq.find(prefixsum - k)!=freq.end())
            {
                count+=freq[prefixsum - k];
            }
               freq[prefixsum]++;
            
        }


        return count;
    }
};