class Solution {
public:
    int maxProfit(vector<int>& nums)
    {
        int profit = 0;

        int left = 0;
        int right = 1;

        while(left < right  && right  < nums.size())
        {
            int temp = nums[right] - nums[left];

            if(nums[right] < nums[left])
            {
                left = right;
                right++;
                continue;
            }

            if(temp > profit)
            {
                profit = temp;
            }
            right++;
        }


        return profit;

    }

};
