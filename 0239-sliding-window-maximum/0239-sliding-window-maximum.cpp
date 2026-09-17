class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for(int right = 0 ; right < nums.size() ; right++)
        {
            while(!dq.empty() && nums[right] > dq.back())
            {
                dq.pop_back();
            }
            dq.push_back(nums[right]);

            if(right>=k && dq.front()==nums[right-k])
            {
                dq.pop_front();
            }

            if(right>=k-1)
            {
                result.push_back(dq.front());
            }

        }

        return result;
    }
};