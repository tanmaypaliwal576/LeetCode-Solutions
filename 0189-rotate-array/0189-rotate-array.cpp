class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int val = k %  nums.size();
        reverse(nums.begin() , nums.end() - val);
        reverse(nums.end() - val, nums.end());
        reverse(nums.begin() , nums.end());
    }
};