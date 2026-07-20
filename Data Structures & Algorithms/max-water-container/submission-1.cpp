class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int size = heights.size();

        int left = 0;
        int right = size - 1;

        int result = INT_MIN;

        while(left < right)
        {
            int area = (right - left) * (min(heights[left], heights[right]));

            result = max(result, area);

            if(heights[left] < heights[right])
            {left++;}
            else
            {right--;}
        }


        return result;
    }
};
