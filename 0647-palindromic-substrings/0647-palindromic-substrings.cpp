class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int start = 0;
        
        for(int i=0 ; i<s.length() ; i++)  
        {
            int left = i;
            int right = i;

            while(left>=0  && right<s.length() && s[left]==s[right])
            {
                count++;
                
            left--;
            right++;
            }


            left = i;
            right = i+1;

            while(left>=0  && right<s.length() && s[left]==s[right])
            {
                count++;
                
            left--;
            right++;
            }


        }

        return count;
    }
};