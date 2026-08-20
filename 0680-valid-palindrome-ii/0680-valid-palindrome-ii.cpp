class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left<right)
        {
            if(tolower(s[left]) != tolower(s[right]))
            {
                return isPalindrome(left+1 , right , s) || isPalindrome(left , right - 1,s);
                
            }
            left++;
            right--;
        }

        return true;

    }

    bool isPalindrome(int left , int right , string s)
    {
        while(left<right)
        {
            if(tolower(s[left]) != tolower(s[right]))
            {
                return false;
                
            }
            left++;
            right--;
        }
        return true;
    }
};