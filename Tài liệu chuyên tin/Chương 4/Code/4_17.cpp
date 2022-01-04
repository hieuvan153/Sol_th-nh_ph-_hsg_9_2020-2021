#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 21;
int n, w, a[maxn], c[maxn];

void KnapSack(int w, int a[], int c[], int n) {
	int dp[w + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i < n + 1; i++) {
		for (int j = w; j >= 0; j--) {
			if (a[i - 1] <= j) {
				dp[j] = max(dp[j], dp[j - a[i - 1]] + c[i - 1]);
			}
		}
	}
	cout << dp[w];
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> c[i];
	}
	KnapSack(w, a, c, n);
}