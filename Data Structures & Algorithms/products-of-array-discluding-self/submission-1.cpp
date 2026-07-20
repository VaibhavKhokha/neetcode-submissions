class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int pre = 1;
        int post = 1;

        vector<int> result(nums.size(), 1);


        for(int i = 0; i<nums.size(); i++)
        {
            result[i] *= pre;

            pre *= nums[i];
        }

        for(int i = nums.size()-1; i>=0; i--)
        {
            result[i] *= post;
            post *= nums[i];
        }

        return result;
    }
};
