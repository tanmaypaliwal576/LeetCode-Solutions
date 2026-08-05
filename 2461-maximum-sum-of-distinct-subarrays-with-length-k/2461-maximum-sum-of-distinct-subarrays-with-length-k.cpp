class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        set<int> st;

        long long sum = 0;

        // First window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            freq[nums[i]]++;
            st.insert(nums[i]);
        }

        long long maxsum = 0;

        if (st.size() == k)
            maxsum = sum;

        // Sliding window
        for (int j = k; j < nums.size(); j++) {

            sum += nums[j];
            freq[nums[j]]++;
            st.insert(nums[j]);

            sum -= nums[j - k];
            freq[nums[j - k]]--;

            if (freq[nums[j - k]] == 0) {
                freq.erase(nums[j - k]);
                st.erase(nums[j - k]);
            }

            if (st.size() == k)
                maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};