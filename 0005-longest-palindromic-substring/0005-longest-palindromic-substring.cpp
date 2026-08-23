class Solution {
public:

    bool isPalindrome(int left, int right, string &s)
    {
        while(left < right)
        {
            if(s[left] != s[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s)
    {
        int n = s.size();

        for(int len = n; len >= 1; len--)
        {
            for(int left = 0; left + len - 1 < n; left++)
            {
                int right = left + len - 1;

                if(isPalindrome(left, right, s))
                {
                    return s.substr(left, len);
                }
            }
        }

        return "";
    }
};