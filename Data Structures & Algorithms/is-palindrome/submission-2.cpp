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
        //return palindrome(s, 0, s.size()-1);

        string newstr = "";

        for(char c : s)
        {
            if(isalnum(c))
            {
                newstr += tolower(c);
            }

        }

        int left = 0;
        int right = newstr.size()-1;

        while(left < newstr.size() && right >=0)
        {
            if(newstr[left] == newstr[right])
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
