#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 15;
int m, n;
string s;
int a[maxn];

int tinh(int curr)
{
    int res = 0;
    int num = 0;
    for (int i = 1; i <= n; i++)
    {
        num = num * 10 + s[i] - 48;
        if (a[i] != 0)
        {
            if (curr == 1)
            {
                res = res + num;
            }
            else
                res = res - num;
            curr = a[i];
            num = 0;
        }
    }
    return res;
}

void duyet(int x)
{
    if (x >= n)
    {
        for (int i = 1; i <= 2; i++)
        {
            if (tinh(i) == m)
            {
                if (a[0] == 2)
                    cout << '-';
                for (int i = 1; i <= n; i++)
                {
                    cout << s[i];
                    if (i != n)
                        if (a[i] == 1)
                        {
                            cout << '+';
                        }
                        else if (a[i] == 2)
                            cout << '-';
                }
                cout << '\n';
            }
        }
        return;
    }
    for (int i = 0; i <= 2; i++)
    {
        a[x] = i;
        duyet(x + 1);
    }
}

signed main()
{
    cin >> m >> s;
    n = s.size();
    s = "@" + s;
    a[n] = 1;
    duyet(1);
}