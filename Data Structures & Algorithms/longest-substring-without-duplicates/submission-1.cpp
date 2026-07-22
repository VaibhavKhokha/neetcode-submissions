class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_set<char> CharSet;
        int left = 0;
        int result = 0;

        for(int right = 0; right < s.size(); right++)
        {
            while(CharSet.find(s[right]) != CharSet.end())
            {
                CharSet.erase(s[left]);
                left++;
            }

            CharSet.insert(s[right]);
            result = max(result, right - left + 1);
        }

        return result;
    }
};