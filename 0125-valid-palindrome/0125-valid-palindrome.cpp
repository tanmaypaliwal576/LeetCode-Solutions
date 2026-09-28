class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        

        while(left < right)
        {
            if(tolower(s[left]) != tolower(s[right]))
            {
                if(!isalnum(s[left]))  left++;
                else if(!isalnum(s[right])) right--;
                else  return false;

               
            }
            else
            {
left++;
            right--;
            }

            
            

        }
        return true;
    }
};