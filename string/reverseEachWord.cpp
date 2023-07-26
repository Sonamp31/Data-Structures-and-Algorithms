#include <bits/stdc++.h>
using namespace std;

void reverseWords(string &s)
{
    string ans = "";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!= ' ')
        {
            st.push(s[i]);
        }
        else
        {
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            ans +=' ';
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    s=ans;

}

int main()
{
    string s = "I love my counntry";

    reverseWords(s);
    cout << s << endl;

    return 0;
}