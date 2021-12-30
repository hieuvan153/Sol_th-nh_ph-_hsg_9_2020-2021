#include <bits/stdc++.h>
#define int long long
using namespace std;

const int SZ = 5500;
int n, t;
int a[SZ][SZ];
int k, rc, x, y;
int q;

void Prep()
{
	cin >> n >> t;
	memset(a, 0, sizeof(a));
	for (int i = 0; i < t; i++)
	{
		cin >> k >> rc >> x >> y;
		if (x > y)
			swap(x, y);
		rc--;
		x--;
		y--;
		int l = y - x + 1;
		if (k == 1)
		{
			if (l % 2 == 1)
			{
				a[rc][x]++;
				a[rc][x + (l + 1) / 2] -= 2;
				if (y < n - 2)
					a[rc][y + 2]++;
				if (rc < n - 1)
				{
					a[rc + 1][x] -= 2;
					a[rc + 1][x + (l + 1) / 2] += 4;
					if (y < n - 2)
					{
						a[rc + 1][y + 2] -= 2;
					}
				}
				if (rc < n - 2)
				{
					a[rc + 2][x] += 1;
					a[rc + 2][x + (l + 1) / 2] -= 2;
					if (y < n - 2)
					{
						a[rc + 2][y + 2]++;
					}
				}
			}
			if (l % 2 == 0)
			{
				a[rc][x]++;
				a[rc][x + l / 2]--;
				a[rc][x + l / 2 + 1]--;
				if (y < n - 2)
					a[rc][y + 2]++;
				if (rc < n - 1)
				{
					a[rc + 1][x] -= 2;
					a[rc + 1][x + l / 2] += 2;
					a[rc + 1][x + l / 2 + 1] += 2;
					if (y < n - 2)
					{
						a[rc + 1][y + 2] -= 2;
					}
				}
				if (rc < n - 2)
				{
					a[rc + 2][x]++;
					a[rc + 2][x + l / 2]--;
					a[rc + 2][x + l / 2 + 1]--;
					if (y < n - 2)
					{
						a[rc + 2][y + 2]++;
					}
				}
			}
		}
		if (k == 2)
		{
			if (l % 2 == 1)
			{
				a[x][rc]++;
				a[x + (l + 1) / 2][rc] -= 2;
				if (y < n - 2)
					a[y + 2][rc]++;
				if (rc < n - 1)
				{
					a[x][rc + 1] -= 2;
					a[x + (l + 1) / 2][rc + 1] += 4;
					if (y < n - 2)
					{
						a[y + 2][rc + 1] -= 2;
					}
				}
				if (rc < n - 2)
				{
					a[x][rc + 2]++;
					a[x + (l + 1) / 2][rc + 2] -= 2;
					if (y < n - 2)
					{
						a[y + 2][rc + 2]++;
					}
				}
			}
			if (l % 2 == 0)
			{
				a[x][rc]++;
				a[x + l / 2][rc]--;
				a[x + l / 2 + 1][rc]--;
				if (y < n - 2)
					a[y + 2][rc]++;
				if (rc < n - 1)
				{
					a[x][rc + 1] -= 2;
					a[x + l / 2][rc + 1] += 2;
					a[x + l / 2 + 1][rc + 1] += 2;
					if (y < n - 2)
					{
						a[y + 2][rc + 1] -= 2;
					}
				}
				if (rc < n - 2)
				{
					a[x][rc + 2]++;
					a[x + l / 2][rc + 2]--;
					a[x + l / 2 + 1][rc + 2]--;
					if (y < n - 2)
					{
						a[y + 2][rc + 2]++;
					}
				}
			}
		}
	}
}

void Solve()
{
	for (int z = 0; z < 2; z++)
	{
		for (int i = 1; i < n; i++)
		{
			a[0][i] += a[0][i - 1];
			a[i][0] += a[i - 1][0];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
	}
}

void Tests()
{
	cin >> q;
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		cout << "\n";
	}
	*/
	for (int i = 0; i < q; i++)
	{
		int x2, y2;
		cin >> x2 >> y2;
		cout << a[x2 - 1][y2 - 1] << "\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Prep();
	Solve();
	Tests();
	return 0;
}
