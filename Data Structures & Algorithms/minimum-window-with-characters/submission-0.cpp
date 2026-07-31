class Solution {
public:
    string minWindow(string s, string t)
    {
        if(t == "")
        {
            return "";
        }

        std::unordered_map<char, int> countT;
        std::unordered_map<char, int> window;

        for(char ch : t)
        {
            countT[ch]++;
        }

        int have = 0;
        int need = countT.size();

        std::pair<std::pair<int, int>, int> result;
        result.first.first = -1;
        result.first.second = -1;
        result.second = INT_MAX;

        int left = 0;

        for(int right = 0; right < s.size(); right++)
        {
            char ch = s[right];
            window[ch]++;

            if(countT.find(ch) != countT.end() && window[ch] == countT[ch])
            {
                have++;
            }

            while(have == need)
            {
                if((right-left+1) < result.second)
                {
                    result.first.first = left;
                    result.first.second = right;

                    result.second = (right-left+1);
                }

                window[s[left]]--;

                if(countT.find(s[left]) != countT.end() && window[s[left]] < countT[s[left]])
                {
                    have--;
                }

                left++;
            }
            
        }

        string result_s = "";

        if(result.second != INT_MAX)
        {
            for(int i = result.first.first; i < result.first.second + 1; i++)
            {
                result_s += s[i];
            }
        }
        else
        {
            return "";
        }

        return result_s;

    }
    
};
