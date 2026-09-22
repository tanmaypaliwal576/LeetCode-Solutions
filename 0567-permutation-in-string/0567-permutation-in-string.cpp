class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> freq;
        unordered_map<int,int> freq_of_s2;

        for(int i=0 ; i<s1.length();i++)
        {
            freq[s1[i]]++;
        }

        int right = 0;
        int left = 0;
        int count = 0;

        while(right < s2.length())  
        {
            
                freq_of_s2[s2[right]]++;
        
                count++;

            while(count > s1.length())
            {
                freq_of_s2[s2[left]]--;
                if(freq_of_s2[s2[left]] == 0)
                    freq_of_s2.erase(s2[left]);

                left++;
                count--;              
            }       

             if(freq == freq_of_s2) 
            {
                return true;
            }
            
            right++;
        }

         
            return false;

    }
};