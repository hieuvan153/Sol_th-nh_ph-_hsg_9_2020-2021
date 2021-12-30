#include <bits/stdc++.h>
using namespace std;
//long long x;
int n,cnt = 0;
vector<int> v(20,0);
bool prime(long long x) {
	long long can = (long long)(sqrt(x));
	if (x<2) return false;
	if ((x==2)||(x==3)) return true;
	if  ((x%2==0)||(x%3==0)) return false;	
	long long k = -1;
	while (k <= can){
		k += 6;
		if((x%k==0) || (x%(k+2)==0) ) break;
	}
	return (k>can);
}
void duyet(int i, long long so){
	if (i>n) v[cnt++] = so;
	else for (int j=0; j<10; j++)
	if (prime(so*10+j)) duyet(i+1, so*10+j);
}
int main() {
	cin >> n;
	duyet(1, 0);
	cout << cnt << endl;
	for(int i = 0;i<cnt;i++) cout << v[i] << " ";
	return 0;
}
