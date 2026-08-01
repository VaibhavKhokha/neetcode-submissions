class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;

        int left = 0;
        int right = 0;

        std::deque<int> que;

        while(right < nums.size())
        {
            while(!que.empty() && nums[que.back()] < nums[right])
            {
                que.pop_back();
            }
            que.push_back(right);

            if(left > que.front())
            {
                que.pop_front();
            }

            if(right + 1 >= k)
            {
                result.emplace_back(nums[que.front()]);
                left++;
            }

            right++;

        }


        return result;

    }

};
