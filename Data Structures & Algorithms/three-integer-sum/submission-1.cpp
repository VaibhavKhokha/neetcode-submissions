class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i = 0; i<nums.size(); i++)
        {
            int left = i+1;
            int right = nums.size()-1;

            while(left<right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                vector<int> temp;
                temp.reserve(3);

                if(sum == 0)
                {
                    temp.emplace_back(nums[i]);
                    temp.emplace_back(nums[left]);
                    temp.emplace_back(nums[right]);

                    if(find(result.begin(), result.end(), temp) == result.end())
                    {
                        result.emplace_back(temp);
                    }
                    
                }
                
                if(sum < 0)
                {
                    left++;
                    continue;
                }
                if(sum > 0)
                {
                    right--;
                    continue;
                }

                left++;
                right--;

            }

        }

        return result;
    }
};
