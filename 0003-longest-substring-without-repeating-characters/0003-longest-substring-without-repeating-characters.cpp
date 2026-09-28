class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        int right = 0;
        int left = 0;
        unordered_map<int,int> freq;
        int result = 0;

        while(right < s.length())
        {
            freq[s[right]]++;
            count++;

            while(freq[s[right]] > 1)
            {
                freq[s[left]]--;
                if(freq[s[left]] == 0) 
                    freq.erase(s[left]);

                left++;
                count--;
            }
            
            result = max(result , count);


            right++;
        }

        return result;
    }
};