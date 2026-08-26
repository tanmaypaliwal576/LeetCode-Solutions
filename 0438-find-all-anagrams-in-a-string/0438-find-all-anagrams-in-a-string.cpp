class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (s.size() < p.size())
            return ans;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        // Count characters of p
        for (int i = 0; i < p.size(); i++) {
            pCount[p[i] - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add character
            sCount[s[right] - 'a']++;

            // Remove extra character
            if (right - left + 1 > p.size()) {
                sCount[s[left] - 'a']--;
                left++;
            }

            // Check if anagram
            if (sCount == pCount) {
                ans.push_back(left);
            }
        }

        return ans;
    }
};