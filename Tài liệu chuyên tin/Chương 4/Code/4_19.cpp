#include <bits/stdc++.h>
using namespace std;

const int maxn = 12;
int m, n, maxx;
int a[maxn][maxn];
int b[maxn][maxn];
int cot[maxn];
int hang[maxn];
int res[maxn][maxn];

void dem() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        if (hang[i]) {
            for (int j = 1; j <= n; j++) {
                b[i][j] = 1 - b[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cot[i]) {
            for (int j = 1; j <= m; j++) {
                b[j][i] = 1 - b[j][i];
            }
        }
    }
    int dem = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dem = dem + b[i][j];
        }
    }
    if (dem > maxx) {
        maxx = dem;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                res[i][j] = b[i][j];
            }
        }
    }
}

void duyet(int x, int y) {
    if (x > m && y > n) {
        dem();
        return;
    }
    if (x > m) {
        for (int i = 0; i < 2; i++) {
            cot[y] = i;
            duyet(x, y + 1);
        }
    }
    else {
        for (int i = 0; i < 2; i++) {
            hang[x] = i;
            duyet(x + 1, y);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("4_19.INP", "r", stdin);
    freopen("4_19.OUT", "w", stdout);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    duyet(1, 1);
    cout << maxx << "\n";
  /*  cout << "  ";
    for (int i = 1; i <= n; i++) {
        cout << cot[i] << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= m; i++) {
        //cout << hang[i] << ' ';
        for (int j = 1; j <= n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }*/
}
