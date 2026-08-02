class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        stack<float> st;
        
        vector<pair<int, int>> combi;
        combi.reserve(position.size());

        for(int i = 0; i<position.size(); i++)
        {
            pair<int, int> temp = {position[i], speed[i]};
            combi.emplace_back(temp);
        }

        sort(combi.rbegin(), combi.rend());

        for(auto& ele : combi)
        {
            float time = (float)(target - ele.first) / (float)ele.second;
            if(st.empty() || time > st.top())
            {
                st.push(time);
            }

        }

        return st.size();
        
        
    }

};
