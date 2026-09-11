class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Find next greater element for every element in nums2
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        // Build answer for nums1
        vector<int> ans;

        for (int num : nums1) {
            if (mp.find(num) != mp.end())
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};