class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.size() > s2.size())
        {
            return false;
        }

        int s1_arr[26] = {0};
        int s2_arr[26] = {0};

        for(char ch : s1)
        {
            s1_arr[int(ch - 'a')] += 1;
        }

        int left = 0;
        int right = left + s1.size() - 1;
        int matches = 0;

        for(int i = left; i <= right; i++)
        {
            s2_arr[int(s2[i] - 'a')] += 1;
        }

        for(int i = 0; i < 26; i++)
        {
            if(s1_arr[i] == s2_arr[i])
            {
                matches++;
            }

        }


        while(right < s2.size()-1)
    {
        if(matches == 26)
            return true;

        int remove = s2[left]-'a';

        if(s2_arr[remove] == s1_arr[remove])
            matches--;

        s2_arr[remove]--;

        if(s2_arr[remove] == s1_arr[remove])
            matches++;


        left++;

        right++;

        int add = s2[right]-'a';

        if(s2_arr[add] == s1_arr[add])
            matches--;

        s2_arr[add]++;

        if(s2_arr[add] == s1_arr[add])
            matches++;

    }

        return matches == 26;
    }
};
