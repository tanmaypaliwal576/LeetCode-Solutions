class Solution {
public:
    int maxArea(vector<int>& height) {
     
        int l = 0;
        int r = height.size() - 1;
        int maxarea = 0;
        while(l<=r)
        {
            int minimum = min(height[l] , height[r]);
            int area = minimum * (r - l);
            if (area > maxarea) maxarea = area;

            if(height[l] <= height[r]) l++;
            else r--;
        }


        return maxarea;
    }
};