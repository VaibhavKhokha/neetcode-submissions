class Solution {
public:

    bool palindrome(string& s, int left, int right)
    {
        if(left >= right)
        {
            return true;
        }

        if(!isalnum(s[left]))
        {
            return palindrome(s,left+1, right);
        }

        if(!isalnum(s[right]))
        {
            return palindrome(s, left, right-1);
        }

        if(tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        return palindrome(s, left+1, right-1);

    }

    bool isPalindrome(string s)
    {
        return palindrome(s, 0, s.size()-1);
    }
};
