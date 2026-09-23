class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<int,int> freq_oft;
        unordered_map<int,int> freq_ofs;

        for(int i = 0; i < t.length(); i++)
        {
            freq_oft[t[i]]++;
        }

        int left = 0;
        int right = 0;

        int formed = 0;
        int required = freq_oft.size();

        int start = 0;
        int minLength = INT_MAX;

        while(right < s.length())
        {
            freq_ofs[s[right]]++;

            if(freq_oft.find(s[right]) != freq_oft.end() &&
               freq_ofs[s[right]] == freq_oft[s[right]])
            {
                formed++;
            }

            while(formed == required)
            {
                // Store only the position and length
                if(right - left + 1 < minLength)
                {
                    start = left;
                    minLength = right - left + 1;
                }

                if(freq_oft.find(s[left]) != freq_oft.end() &&
                   freq_ofs[s[left]] == freq_oft[s[left]])
                {
                    formed--;
                }

                freq_ofs[s[left]]--;

                if(freq_ofs[s[left]] == 0)
                {
                    freq_ofs.erase(s[left]);
                }

                left++;
            }

            right++;
        }

        if(minLength == INT_MAX)
        {
            return "";
        }

        return s.substr(start, minLength);
    }
};