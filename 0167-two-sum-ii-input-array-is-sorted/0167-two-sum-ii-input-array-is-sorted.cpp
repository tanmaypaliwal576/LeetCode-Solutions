class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        int totalsum = 0;


        while(left < right)
        {
            totalsum = numbers[left] + numbers[right];

            if(totalsum == target)
            {
                return {left+1 , right +1};
            }
            else if(totalsum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return {};
    }
};