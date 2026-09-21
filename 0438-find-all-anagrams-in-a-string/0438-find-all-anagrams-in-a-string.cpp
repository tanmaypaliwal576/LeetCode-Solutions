class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_map<int,int> freq;
        unordered_map<int,int> freq_of_anagram;
        vector<int> result;

        for(int i = 0; i<p.length();i++)
        {
            freq_of_anagram[p[i]]++;
        }

        while(right<s.length())
        {
            if (p.find(s[right]) != string::npos) //if it consists so it will give index otherwise it will give npos(no position)
            {
            freq[s[right]]++;
            }
            
                count++;

           
            while(count > p.length())
            {
               if (freq.find(s[left]) != freq.end()) //check if there is freq[nums[left]] is there or not?
                    freq[s[left]]--;
                if(freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
                count--;
            }

            if(freq == freq_of_anagram)
            {
                result.push_back(left);
            }
            right++;
        }
        
        return result;
    }
};