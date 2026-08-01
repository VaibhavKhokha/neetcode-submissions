class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int result = 0;

        stack<int> st;

        for(string s : tokens)
        {
            if(s != "+" && s != "-" && s != "*" && s != "/")
            {
                st.push(stoi(s));
            }

            if(s == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b+a);
            }
            else if(s == "-")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b - a);
            }
            else if(s == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b*a);
            }
            else if(s == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b/a);
            }
            else
            {
                cout << "invalid";
            }
        }

        return st.top();

    }

};
