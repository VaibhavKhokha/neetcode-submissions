class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int numax = 0;

        for(int num : numSet)
        {
            if(numSet.find(num-1) != numSet.end())
            {
                continue;
            }
            int length = 1;

            while(num != INT_MAX && numSet.find(num+1) != numSet.end())
            {
                length++;
                num++;
            }

            numax = max(numax, length);

        }

        return numax;

    }
};
