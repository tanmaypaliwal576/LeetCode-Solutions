class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            // Skip non-alphanumeric characters from left
            while(left < n && !isalnum(s[left]))
                left++;

            // Skip non-alphanumeric characters from right
            while(right >= 0 && !isalnum(s[right]))
                right--;

            // Important: pointers may have crossed
            if(left >= right)
                return true;

            // Compare characters
            if(tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};