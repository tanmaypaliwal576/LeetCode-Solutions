class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        unordered_map<string,int> freq_of_words;

        int wordlen = words[0].length();

        vector<int> result;

        for(int i = 0; i < words.size(); i++)
        {
            freq_of_words[words[i]]++;
        }

        
        for(int start = 0; start < wordlen; start++)
{
    int left = start;
    int right = start;

    unordered_map<string,int> freq_of_s;
    int count = 0;

    while(right + wordlen <= s.length())
    {
        string temp = s.substr(right, wordlen);

        if(freq_of_words.find(temp) == freq_of_words.end())
        {
            freq_of_s.clear();
            count = 0;
            right += wordlen;
            left = right;
            continue;
        }

        freq_of_s[temp]++;
        count++;
        right += wordlen;

        while(freq_of_s[temp] > freq_of_words[temp])
        {
            string remove = s.substr(left, wordlen);

            freq_of_s[remove]--;
            count--;
            left += wordlen;
        }

        if(count == words.size())
        {
            result.push_back(left);
        }
    }
}

        return result;
    }
};