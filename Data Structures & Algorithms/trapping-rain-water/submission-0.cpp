class Solution {
public:
    int trap(vector<int>& height)
    {
        if(height.empty())
        {return 0;}

        vector<int> maxLeft;
        maxLeft.reserve(height.size());

        vector<int> maxRight(height.size(), 0);

        int ml = height[0];
        int mr = height.back();

        maxLeft.emplace_back(ml);

        for(int i = 1; i<height.size(); i++)
        {
            ml = max(ml, height[i]);
            maxLeft.emplace_back(ml);
        }

        maxRight.back() = mr;

        for(int i = maxRight.size() - 2; i>=0; i--)
        {
            mr = max(mr, height[i]);

            maxRight[i] = mr;
        }

        vector<int> minLR;
        minLR.reserve(height.size());

        for(int i = 0; i<maxLeft.size(); i++)
        {
            minLR.emplace_back(min(maxLeft[i], maxRight[i]) - height[i]);
        }

        int result = 0;

        for(int num : minLR)
        {
            result += num;
        }

        return result;
    }

};
