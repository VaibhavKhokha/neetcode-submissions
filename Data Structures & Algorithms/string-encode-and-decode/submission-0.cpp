class Solution {
public:

    string encode(vector<string>& strs)
    {
        size_t N = strs.size();

        string encoded = "";

        for(size_t i = 0; i<N; i++)
        {
            encoded += to_string(strs[i].size());

            encoded += '#';

            for(char ch : strs[i])
            {
                encoded += ch;
            }
        }

        return encoded;
    }

    string makestring(string& s, size_t start, size_t size)
    {
        string result = "";
        for(int i  = start; i< start+size; i++)
        {
            result+=s[i];
        }
        return result;
    }

    vector<string> decode(string s)
    {
        string num = "";
        size_t i = 0;

        vector<string> result;

        while (i < s.size())
        {
            if(s[i] == '#')
            {
                size_t len = stoul(num);
                num.clear();

                string final = makestring(s, i+1, len);
                result.emplace_back(final);
                i += (len+1);
                continue;
            }

            num  += s[i];

            i++;
        }

        return result;
    }
};
