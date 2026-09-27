class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right  = height.size() - 1;
        int result = 0;

        while(left < right)
        {
            int width = right - left;
            int lowest = min(height[right] , height[left]);
            int ans = width * lowest;
            result = max(result , ans );
             if(height[right]<=height[left])
            {
                right--;
            }
            else
            {
                left++;
            }

        }

        return result;
    }
};