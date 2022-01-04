#include <bits/stdc++.h>
#define fi first
#define se second
#define pair_CI pair <char, int>
#define map_SB map <string, bool>
using namespace std;
const int Sz = 20;
pair_CI s[Sz];
int n, res;
vector<string> v;
string c;

void FastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void ReadData() {
    n = 0;
    cin >> c;

    for (int i = 0; i < c.size(); i++) {
        n++;
        s[n].fi = c[i];
        s[n].se = 0;
    }
}

void Duyet(int x) {
    if (x > n) {
        string tmp = "";
        for (int i = 1; i <= n; i++)
            if (s[i].se == 1)
                tmp = tmp + s[i].fi;

        if (tmp != "") {
            v.push_back(tmp);
        }
    }
    else
        for (int i = 0; i <= 1; i++) {
            s[x].se = i;
            Duyet(x + 1);
        }
}

void Solve() {
    res = 0;

    Duyet(1);

    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    cout << v.size() << '\n';

    for (string x : v) cout << x << '\n';
}

signed main() {
    FastIO();
    freopen("4_6.inp", "r", stdin);
    freopen("4_6.out", "w", stdout);
    ReadData();
    Solve();
}