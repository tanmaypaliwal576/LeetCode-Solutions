class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> mp;

        for (int i = 0; i < wordCount; i++) {
            mp[words[i]]++;
        }

        for (int start = 0; start < wordLen; start++) {

            int left = start;
            int count = 0;

            unordered_map<string, int> seen;

            for (int right = start; right + wordLen <= s.size(); right += wordLen) {

                string word = s.substr(right, wordLen);

                if (mp.find(word) == mp.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > mp[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};