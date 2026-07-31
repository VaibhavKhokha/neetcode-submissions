class Solution {
public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<char, int> count;
        int result = 0;

        int left = 0;
        int maxfreq = 0;

        for(int right = 0; right<s.size(); right++)
        {
            count[s[right]] += 1;

            maxfreq = max(maxfreq, count[s[right]]);

            while((right-left+1) - maxfreq > k)
            {
                count[s[left]] -= 1;
                left++;
            }

            result = max(result, right-left+1);
        }

        return result;

    }

};
