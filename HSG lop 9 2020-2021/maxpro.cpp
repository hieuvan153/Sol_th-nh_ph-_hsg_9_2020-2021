#include <bits/stdc++.h>
using namespace std;
const int SZ = 1e5 + 5;

long long a[5], M;

void ReadData()
{
	cin >> a[0] >> a[1] >> a[2] >> M;
}

long long tich(long long a, long long b, long long M)
{
	if (a == 0 || b == 0)
		return 0;
	a = a % M;
	b = b % M;
	long long du = 0;
	while (1)
	{
		if (b % 2 == 1)
			du = (du + a) % M;
		a = a * 2 % M;
		b /= 2;
		if (b == 1)
			break;
	}
	return (a + du) % M;
}

long long tich_dq(long long a, long long b, long long M)
{
	if (b <= 1)
		return a * b % M;
	return (tich_dq(a * 2 % M, b / 2, M) + a * (b % 2)) % M;
}

void Solve()
{
	sort(a, a + 3);
	if (a[1] < 0)
		cout << tich(-a[0], -a[1], M);
	else
		cout << tich(a[2], a[1], M);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	ReadData();
	Solve();

	return 0;
}