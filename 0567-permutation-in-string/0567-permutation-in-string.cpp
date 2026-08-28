class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length())
            return false;

        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for (int i = 0; i < s1.length(); i++) {
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        if (a == b)
            return true;

        int left = 0;

        for (int right = s1.length(); right < s2.length(); right++) {
            b[s2[right] - 'a']++;
            b[s2[left] - 'a']--;

            left++;

            if (a == b)
                return true;
        }

        return false;
    }
};