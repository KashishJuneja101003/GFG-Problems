class Solution {
  public:
    string decodedString(string &s) {
        stack<char> stk;

        string result = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                stk.push(s[i]);
            } else {
                string str = "";

                while (!stk.empty() && stk.top() != '[') {
                    str = stk.top() + str;
                    stk.pop();
                }

                stk.pop();

                string n = "";

                while (!stk.empty() && isdigit(stk.top())) {
                    n = stk.top() + n;
                    stk.pop();
                }

                int num = stoi(n);

                for (int i = 0; i < num; i++) {
                    for (char& c : str)
                        stk.push(c);
                }
            }
        }

        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        return result;
    }
};
