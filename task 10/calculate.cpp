#include <express.h>

express* calculate(string st)
{
    int level = 0;
    for (int i = st.length() - 1; i >= 0; i--)
    {
        if (level == 0)
        {
            if (st[i] == '-')
                return new subtract(calculate(st.substr(0, i)), calculate(st.substr(i + 1, st.length() - i - 1)));
            if (st[i] == '+')
                return new sum(calculate(st.substr(0, i)), calculate(st.substr(i + 1, st.length() - i - 1)));
        }
        if (st[i] == '(') level++;
        if (st[i] == ')') level--;
    }
    level = 0;
    for (int i = st.length() - 1; i >= 0; i--)
    {
        if (level == 0)
        {
            if (st[i] == '*')
                return new multiply(calculate(st.substr(0, i)), calculate(st.substr(i + 1, st.length() - i - 1)));
            if (st[i] == '/')
                return new divide(calculate(st.substr(0, i)), calculate(st.substr(i + 1, st.length() - i - 1)));
        }
        if (st[i] == '(') level++;
        if (st[i] == ')') level--;
    }
    if (st[0] == '(' && st[st.length() - 1] == ')') return calculate(st.substr(1, st.length() - 2));
    return new number(stoi(st));
}
