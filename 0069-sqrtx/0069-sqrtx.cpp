class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;
        while(low<=high)
        {
            int mid = (low + high ) / 2;
            if((long long)mid*mid == x)
            {
                return mid;
            }
            else if((long long)mid*mid > x)
            {
                high = mid - 1;
            }
            else{
                low = mid + 1;
                ans = mid;
            }
        }

        return ans;
    }
};