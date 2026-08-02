class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int maxArea = 0;

        vector<pair<int, int>> st;

        for(int i = 0; i<heights.size(); i++)
        {
            int start = i;

            while(!st.empty() && st.back().second > heights[i])
            {
                int index = st.back().first;
                int height = st.back().second;

                st.pop_back();

                maxArea = max(maxArea, height * (i - index));

                start = index;

            }
            st.push_back({start, heights[i]});

        }

        for(auto& ele : st)
        {
            maxArea = max(maxArea, (int)(ele.second * (heights.size() - ele.first)));
        }

        return maxArea;

    }
};
