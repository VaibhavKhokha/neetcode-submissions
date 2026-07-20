class Solution {
public:

    bool isPalindrome(string s)
    {

        int left = 0;
        int right = s.size()-1;

        while(left < right)
        {
            while(!isalnum(s[left]) && left < s.size())
            {
                left++;
            }

            while(!isalnum(s[right]) && right >=0)
            {
                right--;
            }

            if(tolower(s[left]) == tolower(s[right]))
            {
                left++;
                right--;
                continue;
            }

            return false;
        }

        return true;
    }
};
