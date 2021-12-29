#include <bits/stdc++.h>
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
#define db double
const int maxn = 5005;
int a[maxn], b[maxn];
using namespace std;
int main() {
    fastread();
	int n;
	cin >> n;
	char c;
	for (int i=1;i<=n*n;i++) {
		cin >> c;
		if (c == 'X') {
			if (i%n == 0) a[n]++;
			else a[i%n]++;
		}
	}
	int j=1, Max = 0, cnt = 0;
	for (int i=1;i<=n;i++) Max = max(Max,a[i]);
	for (int i=1;i<=n;i++) {
		if (a[i] == Max) {
			cnt++;
			b[j] = i;
			j++;
		}
	}
	cout << cnt << " " << Max <<"\n";
	for (int i=1;i<=cnt;i++) cout << b[i] << " ";
	}