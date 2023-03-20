#include <string>
#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> st;
    string s;
    cin >> s;
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push('(');
        else
        {
            if (st.size() == 0)
            {
                count++;
            }
            else
                st.pop();
        }
    }
    cout << st.size()+count;
}