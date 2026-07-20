class Solution {
public:

    bool isPalindrome(string s)
    {

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
