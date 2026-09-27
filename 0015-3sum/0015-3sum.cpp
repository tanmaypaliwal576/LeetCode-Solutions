class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> result;
        for(int i=0 ; i<nums.size();i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            

            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0 )
                {
                    j++;
                }
                else
                {
                    
                        result.insert({nums[i],nums[j],nums[k]});


                    j++;
                    k--;

                }
            }

        }

         return vector<vector<int>>(result.begin(), result.end());
    }
};