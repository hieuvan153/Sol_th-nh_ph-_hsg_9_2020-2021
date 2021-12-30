#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010, base = 31, mod = 1e9 + 7;
int m, n;
int a[maxn][maxn];
int has[maxn][maxn];
set<int> check;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n;
    char c;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            a[i][j] = c - 'a' + 1;
        }
    }
    for (int i = m; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            has[i][j] = (has[i + 1][j] * base + a[i][j]) % mod;
        }
    }
    int l = 1, r = m, ans = 1;
    while (l <= r)
    {
        check.clear();
        bool ok = true;
        int mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
        {
            if (check.count(has[mid][i]))
            {
                ok = false;
                break;
            }
            check.insert(has[mid][i]);
        }
        if (ok)
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    cout << ans - 1;
}