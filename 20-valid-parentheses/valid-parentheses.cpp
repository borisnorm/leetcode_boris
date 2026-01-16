class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
          return false;
        
        unordered_map<char, char> l2r = {
            {'(', ')'}, {'[', ']'}, {'{', '}'}
        };
        stack<char> st;
        for (char c : s)
        {
            if (l2r.count(c))
            {
                st.push(c);
            }
            else
            {
                // check more right parenthese
                if (st.empty())
                  return false;
                
                if (c != l2r[st.top()])
                  return false;

                st.pop();
            }
        }

        return st.empty() ? true : false;
    }
};