class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0;
        int high = height.size() - 1;
        int leftmax = height[low];
        int rightmax = height[high];
        int water = 0;
        while(low<high)
        {
            if(leftmax <=  rightmax)
            {
                low++;
                leftmax = max(leftmax , height[low]);
                water += leftmax - height[low];
            }
            else
            {
                high--;
                rightmax = max(rightmax , height[high]);
                water+= rightmax - height[high];
            }
            
            
        }

        return water;
    }
};