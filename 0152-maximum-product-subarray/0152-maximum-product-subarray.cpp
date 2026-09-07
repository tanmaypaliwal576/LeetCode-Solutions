class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftproduct = 1;
        int rightproduct = 1;
        int max_product = nums[0];

        for (int i = 0; i < nums.size(); i++) {

            if (leftproduct == 0)
                leftproduct = 1;

            if (rightproduct == 0)
                rightproduct = 1;

            leftproduct *= nums[i];
            rightproduct *= nums[nums.size() - 1 - i];

            max_product = max({max_product, leftproduct, rightproduct});
        }

        return max_product;
    }
};