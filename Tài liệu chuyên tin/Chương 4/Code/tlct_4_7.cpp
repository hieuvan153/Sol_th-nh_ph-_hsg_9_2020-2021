#include <bits/stdc++.h>
using namespace std;

void solve(int n, int open, int close, string s, vector<string> &ans){
	if(open == n && close == n){
		ans.push_back(s);
		return;
	}	
	if(open < n){
		solve(n, open + 1, close, s + "(", ans);
	}
	if(close < open){
		solve(n, open, close + 1, s + ")", ans);
	}
}

int main() {
	freopen("4_7.INP","r",stdin);
	freopen("4_7.OUT","w",stdout);
	int n;
	cin >> n;
	vector<string> ans;
	solve(n, 0, 0, "", ans);
	cout << ans.size() << endl;
	for(auto s:ans){
		cout << s << "\n";
	}
	return 0;
}
