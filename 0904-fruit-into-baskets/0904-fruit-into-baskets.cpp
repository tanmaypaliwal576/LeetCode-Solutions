class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int right = 0;
        int left = 0;
        int result = 0;
        int count = 0;
        while(right < fruits.size())
        {
            freq[fruits[right]]++;
            count++;

            while(freq.size() > 2)
            {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0)
                    freq.erase(fruits[left]);
                left++;
                count--;
            }
            right++;

            result = max(result , count);


        }

        return result;
    }
};