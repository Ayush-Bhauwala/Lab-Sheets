#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<string> st;
    string s;
    cin >> s;
    int i = s[0] == '/' ? 1 : 0;
    string temp = "";
    for (i; i < s.length(); i++)
    {
        if (i == s.length() - 1 && temp.compare("") && s[i] != '/')
        {
            temp += s[i];
            if (!temp.compare(".."))
            {
                if (st.size() != 0)
                    st.pop();
            }
            else if (!temp.compare("."))
            {
            }
            else if (temp.compare(""))
            {
                st.push(temp);
            }
        }
        if (s[i] != '/')
        {
            temp += s[i];
        }
        else
        {
            if (!temp.compare(".."))
            {
                if (st.size() != 0)
                    st.pop();
            }
            else if (!temp.compare("."))
            {
            }
            else if (temp.compare(""))
            {
                st.push(temp);
            }
            temp = "";
        }
    }
    stack<string> newst;
    while (!st.empty())
    {
        // cout << st.top();
        newst.push(st.top());
        st.pop();
    }
    if (newst.empty())
        cout << "/";
    while (!newst.empty())
    {
        cout << "/" << newst.top();
        newst.pop();
    }
    return 0;
}