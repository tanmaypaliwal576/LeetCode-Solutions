class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> result;

    if(nums.empty() || nums.size()<3) return vector<vector<int>>(result.begin() , result.end());
            
        for(int i=0 ; i<nums.size() - 2 ; i++)
            
        {
            int j = i+1;
            int k = nums.size() - 1;
            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    result.insert({nums[i] , nums[j] , nums[k]});
                    j++;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else{
                    j++;
                }
            }
        }

         return vector<vector<int>>(result.begin() , result.end());
    }
};