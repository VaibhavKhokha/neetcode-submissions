class Solution {
public:
    bool isValid(string s)
    {
        std::stack<char> ch_st;

        for(char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                ch_st.push(ch);
            }
            else
            {
                if(ch_st.empty())
                {
                    return false;
                }

                if(ch == ')' && ch_st.top() == '(')
                {
                    ch_st.pop();
                }
                else if(ch == '}' && ch_st.top() == '{')
                {
                    ch_st.pop();
                }
                else if(ch == ']' && ch_st.top() == '[')
                {
                    ch_st.pop();
                }
                else
                {
                    return false;
                }

            }
           
        }

        if(ch_st.empty())
        {
            return true;
        }

        return false;

    }
};
