class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                return 0;
            }
        }

        int left = 0;
        int right = nums.size();

        int prevIndex = 0;

        while(left < right)
        {
            int index = (left + right)/2;

            if(prevIndex == index)
            {
                break;
            }

            if(nums[index] == target)
            {
                return index;
            }

            if(target > nums[index])
            {
                left = index;
            }
            else if(target < nums[index])
            {
                right = index;
            }

            prevIndex = index;
        }

        return -1;
    }

};
