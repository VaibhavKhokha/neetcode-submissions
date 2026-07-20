class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> numSet;
        
        int count = 0;
        int numax = 0;

        for(int num : nums)
        {
            numSet.insert(num);
        }

        for(int num : nums)
        {
            if(numSet.find(num-1) != numSet.end())
            {
                continue;
            }
            else
            {
                count ++;
            }

            while(numSet.find(num+1) != numSet.end())
            {
                count++;
                num++;
            }

            numax = max(numax, count);
            count = 0;

        }

        return numax;

    }
};
